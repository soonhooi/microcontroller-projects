#include "stm32f4xx_hal.h"

#include <I2CHAL.h>
#include <SerialHAL.h>
#include <TimerHAL.h>
#include <dcutil/persist.h>

#include "motor/motor.h"

#include "Chiindii.h"

//The period (in ms) since we last saw a message, after which we assume the comm link is dead and we disarm the craft
#define COMM_TIMEOUT_PERIOD		3000
//The time since the last "low battery" warning was sent, as needed
#define LAST_LOW_BATTERY_TIME	1000
//The number of Z-gyro samples to average
#define GYRO_AVERAGE_COUNT 25
//The number of Z-gyro samples to average
#define GFORCE_AVERAGE_COUNT 25


//The variables defined in CubeMX generated code
extern IWDG_HandleTypeDef hiwdg;
extern UART_HandleTypeDef huart6;
extern I2C_HandleTypeDef hi2c2;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim5;

using namespace digitalcave;

extern "C" {
	void chiindii_main();
}

void chiindii_main(){
	// Turn off active low LED (set pins high)
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);		//Red
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);		//Green
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_SET);		//Blue

	battery_init();
	timer_init();

	SerialHAL serialHal(&huart6, 128);
	I2CHAL i2cHal(&hi2c2);

	Chiindii chiindii(&serialHal, &i2cHal);
	chiindii.run();
	while(1);
}

Chiindii::Chiindii(Stream* serial, I2C* i2c) :
	serial(serial),
	i2c(i2c),

	mpu6050(i2c),
	ms5611(i2c),
	hmc5883l(i2c),

	protocol(128),

	mode(MODE_UNARMED),
	battery_level(0),
	throttle_sp(0),
	angle_sp({0, 0, 0}),
	rate_sp({0, 0, 0}),

	rate_x(0.1, 0, 0, DIRECTION_NORMAL, 0),
	rate_y(0.1, 0, 0, DIRECTION_NORMAL, 0),
	rate_z(0.1, 0, 0, DIRECTION_NORMAL, 0),

	angle_x(0.1, 0, 0, DIRECTION_NORMAL, 0),
	angle_y(0.1, 0, 0, DIRECTION_NORMAL, 0),
	angle_z(0.1, 0, 0, DIRECTION_NORMAL, 0),

	gforce(0.1, 0, 0, DIRECTION_NORMAL, 0),

	imu(0.01, 0),

	general(this),
	universalController(this)
{
	//Turn off motors
	motor_stop();

	//Output of angle PID is a rate (rad / s) for each axis.
	angle_x.setOutputLimits(-10, 10);
	angle_y.setOutputLimits(-10, 10);
	angle_z.setOutputLimits(-1, 1);

	//Output of g-force PID
	gforce.setOutputLimits(0, 2);

	//Output of rate PID is an acceleration (rad / s / s) for each axis
	rate_x.setOutputLimits(-4, 4);
	rate_y.setOutputLimits(-4, 4);
	rate_z.setOutputLimits(-1, 1);
}

void Chiindii::run() {
	FramedSerialMessage request(0, 128);

	loadConfig(); // load previously saved PID and comp tuning values from EEPROM

	vector_t accel = {0, 0, 0};
	vector_t gyro = {0, 0, 0};
	vector_t mag = {0, 0, 0};

	vector_t rate_pv = {0, 0, 0};
	vector_t angle_mv = {0, 0, 0};

	float gyro_z_average = 0;
//	float gforce_z_average = 1;
	uint32_t time = 0;
	uint32_t lastReceiveMessageTime = 0;
	uint32_t lastLowBatteryTime = 0;
	float lowBatteryThrottle = 0;
	uint16_t loopCounter = 0;

	motor_start();

	delay_ms(250);

	//Watchdog timer
	HAL_IWDG_Start(&hiwdg);

	//Main program loop
	while (1) {
		HAL_IWDG_Refresh(&hiwdg);
		time = timer_millis();

		if (protocol.read(serial, &request)) {
			uint8_t cmd = request.getCommand();

			if ((cmd & 0xF0) == 0x00){
				general.dispatch(&request);
			}
			else if ((cmd & 0xF0) == 0x10){
				universalController.dispatch(&request);
			}
			else {
				//TODO Send debug message 'unknown command' or similar
			}
			lastReceiveMessageTime = time;
			status.commOK();
		}
		else if ((time - lastReceiveMessageTime) > COMM_TIMEOUT_PERIOD) {
			if (mode) sendStatus("Comm Timeout  ", 14);
			mode = MODE_UNARMED;
			status.commInterrupt();
		}

		battery_level = battery_read();
		if (battery_level > BATTERY_WARNING_LEVEL) {
			status.batteryOK();
			lowBatteryThrottle -= 0.0001;
			if (lowBatteryThrottle < 0){
				lowBatteryThrottle = 0;
			}
		}
		else if (battery_level > BATTERY_DAMAGE_LEVEL) {
			status.batteryLow();
		}
		else if (battery_level <= 1) {
			//The battery should only read as 0 (or 1) if it is completely unplugged; we assume that we
			// are running in debug mode without any battery.  We still show the battery
			// status light, but we don't exit from armed mode.
			status.batteryLow();
		}
		else {
			if ((time - lastLowBatteryTime) > LAST_LOW_BATTERY_TIME){
				sendStatus("Low Battery   ", 14);
			}
			lowBatteryThrottle += 0.0001;
			status.batteryLow();
			if (lowBatteryThrottle > 0.75){
				mode = MODE_UNARMED;
			}
		}

		//Update IMU calculations.
		accel = mpu6050.getAccel();
		gyro = mpu6050.getGyro();
		mag = hmc5883l.getMag();

		gyro_z_average = gyro_z_average + gyro.z - (gyro_z_average / GYRO_AVERAGE_COUNT);

		//Send telemetry if something is strange...
// 		if (accel.x > 1 || accel.x < -1 || accel.y > 1 || accel.y < -1 || accel.z > 2 || accel.z < 0){
// 			int16_t telemetry[4];
// 			telemetry[0] = loopCounter;
// 			telemetry[1] = accel.x * 1000;
// 			telemetry[2] = accel.y * 1000;
// 			telemetry[3] = accel.z * 1000;
// 			FramedSerialMessage response(0x24, (uint8_t*) telemetry, 8);
// 			sendMessage(&response);
// 		}

		imu.compute(accel, gyro, mag, mode, time);
//		gforce_z_average = gforce_z_average + imu.getZAcceleration(accel) - (gforce_z_average / GFORCE_AVERAGE_COUNT);

		//Update PID calculations and adjust motors
		angle_mv = imu.getEuler();

		float throttle;

		//We only do angle PID in mode angle or throttle.
		if (mode == MODE_ARMED_THROTTLE) { // 0x02
			// angle pid with direct throttle
			// compute a rate set point given an angle set point and current measured angle
			// see doc/control_system.txt
			rate_sp.x = angle_x.compute(angle_sp.x, angle_mv.x, time);
			rate_sp.y = angle_y.compute(angle_sp.y, angle_mv.y, time);
			rate_sp.z = angle_z.compute(angle_sp.z, angle_mv.z, time);
			gforce.reset(time);

// 			char temp[14];
// 			snprintf(temp, sizeof(temp), "%3d %3d %3d        ", (uint16_t) radToDeg(angle_sp.z), (uint16_t) radToDeg(angle_mv.z), (int16_t) (rate_sp.z * 100));
// 			sendDebug(temp, 14);

			throttle = throttle_sp;
		}
		else { // unarmed
			angle_x.reset(time);
			angle_y.reset(time);
			angle_z.reset(time);
			gforce.reset(time);

			angle_sp.z = angle_mv.z;	//Reset heading to measured value
			throttle = throttle_sp;

// 			char temp[14];
// 			snprintf(temp, sizeof(temp), "%3d %3d N/A        ", (uint16_t) radToDeg(angle_sp.z), (uint16_t) radToDeg(angle_mv.z));
// 			sendDebug(temp, 14);
		}

		throttle -= lowBatteryThrottle;
		if (throttle < 0) throttle = 0;

		//We always want to do rate PID when armed; if we are in rate mode, then we use the rate_sp as passed
		// by the user, otherwise we use rate_sp as the output of angle PID.
		if (mode){
			// rate pid
			// computes the desired change rate
			// see doc/control_system.txt
			rate_pv.x = rate_x.compute(rate_sp.x, gyro.x, time);
			rate_pv.y = rate_y.compute(rate_sp.y, gyro.y, time);
			rate_pv.z = rate_z.compute(rate_sp.z, gyro_z_average / GYRO_AVERAGE_COUNT, time);

// 			char temp[14];
// 			snprintf(temp, sizeof(temp), "%3d %3d %3d     ", (int16_t) (angle_sp.z * 100), (int16_t) ((gyro_z_average / GYRO_AVERAGE_COUNT) * 100), (int16_t) (rate_pv.z * 100));
// 			sendDebug(temp, 14);

			//This is the weight which we give to throttle relative to the rate PID outputs.
			// Keeping this too low will result in not enough throttle control; keeping it too high
			// will result in not enough attitude control.
			//By making this dynamic, we allow for more throttle control at the bottom of the throttle
			// range, and more manouverability at the middle / top.
			float throttleWeight = fmax(-3.0 * throttle + 2.5, 1);
			throttle = throttle * throttleWeight;

			//Give a bit more throttle when pitching / rolling.  The magic number '10' means that, with a max of 30 degrees (~0.5 radians)
			// as the set point, we will add at most 0.05 (5%) to the throttle.
			throttle += fmax(abs(angle_sp.x), abs(angle_sp.y)) / 10;

			//The 2.1 hardware supports up to 8 motors
			float m[8];

#if MOTOR_COUNT == 8
			//This assumes an MPU that has a gyro output corresponding to the notes in doc/motor_arrangement.txt, in X + T configuration
			m[0] = throttle + rate_pv.x - rate_pv.y - rate_pv.z;
			m[1] = throttle - rate_pv.y + rate_pv.z;
			m[2] = throttle - rate_pv.x + rate_pv.y - rate_pv.z;
			m[3] = throttle + rate_pv.y + rate_pv.z;
			m[4] = throttle + rate_pv.x + rate_pv.z;
			m[5] = throttle - rate_pv.x - rate_pv.y - rate_pv.z;
			m[6] = throttle - rate_pv.x + rate_pv.z;
			m[7] = throttle + rate_pv.x + rate_pv.y - rate_pv.z;
#elif MOTOR_COUNT == 4
			m[0] = throttle + rate_pv.x - rate_pv.y + rate_pv.z;
			m[1] = 0;
			m[2] = throttle - rate_pv.x + rate_pv.y + rate_pv.z;
			m[3] = 0;
			m[4] = 0;
			m[5] = throttle - rate_pv.x - rate_pv.y - rate_pv.z;
			m[6] = 0;
			m[7] = throttle + rate_pv.x + rate_pv.y - rate_pv.z;
#else
			#warning Invalid motor count
#endif
			for (uint8_t i = 0; i < 8; i++){
				if (m[i] < 0) m[i] = 0;
				else if (m[i] > throttleWeight) m[i] = throttleWeight;

				m[i] = m[i] / throttleWeight;
			}

			motor_set(m);

			status.armed();
		}
		else {
			//If we are not armed, keep the PID reset.  This prevents erratic behaviour
			// when initially turning on, especially if I is non-zero.
			rate_x.reset(time);
			rate_y.reset(time);
			rate_z.reset(time);
			angle_x.reset(time);
			angle_y.reset(time);
			angle_z.reset(time);
			gforce.reset(time);

			status.disarmed();
			motor_stop();
		}

// #ifdef DEBUG
// 		if (debug){
// 			char temp[128];
// 			if (mode){
// 				snprintf(temp, sizeof(temp), "Gyro: %4d, %4d, %4d  ", (int16_t) radToDeg(gyro.x), (int16_t) radToDeg(gyro.y), (int16_t) radToDeg(gyro.z));
// 				sendDebug(temp);
// 			}
// 			if (mode == MODE_ARMED_THROTTLE || mode == MODE_ARMED_ANGLE || mode == MODE_SHOW_VARIABLES){
// 				snprintf(temp, sizeof(temp), "Accel: %4d, %4d, %4d  ", (int16_t) (accel.x * 100), (int16_t) (accel.y * 100), (int16_t) (accel.z * 100));
// 				sendDebug(temp);
// 				snprintf(temp, sizeof(temp), "Angle MV: %4d, %4d, %4d  ", (int16_t) radToDeg(angle_mv.x), (int16_t) radToDeg(angle_mv.y), (int16_t) radToDeg(angle_mv.z));
// 				sendDebug(temp);
// 				snprintf(temp, sizeof(temp), "Rate SP: %3d, %3d, %3d  ", (int16_t) (rate_sp.x * 100), (int16_t) (rate_sp.y * 100), (int16_t) (rate_sp.z * 100));
// 				sendDebug(temp);
// 			}
// 			if (mode){
// 				snprintf(temp, sizeof(temp), "Rate PV: %3d, %3d, %3d  ", (int16_t) (rate_pv.x * 100), (int16_t) (rate_pv.y * 100), (int16_t) (rate_pv.z * 100));
// 				sendDebug(temp);
// 			}
// 			if (mode == MODE_SHOW_VARIABLES){
// 				sendDebug("\n");
// 			}
// 		}
// #endif

		status.poll(time);

		loopCounter++;
	}
}

void Chiindii::loadConfig(){
	uint8_t config[116];
	persist_read(0, config, sizeof(config));

	if (config[0] == 0x42 && config[1] == 0x42){
		float kp, ki, kd;
		uint8_t i = 2;

		kp = (float) *(&config[i+=4]);
		ki = (float) *(&config[i+=4]);
		kd = (float) *(&config[i+=4]);
		rate_x.setTunings(kp, ki, kd);

		kp = (float) *(&config[i+=4]);
		ki = (float) *(&config[i+=4]);
		kd = (float) *(&config[i+=4]);
		rate_y.setTunings(kp, ki, kd);

		kp = (float) *(&config[i+=4]);
		ki = (float) *(&config[i+=4]);
		kd = (float) *(&config[i+=4]);
		rate_z.setTunings(kp, ki, kd);

		kp = (float) *(&config[i+=4]);
		ki = (float) *(&config[i+=4]);
		kd = (float) *(&config[i+=4]);
		angle_x.setTunings(kp, ki, kd);

		kp = (float) *(&config[i+=4]);
		ki = (float) *(&config[i+=4]);
		kd = (float) *(&config[i+=4]);
		angle_y.setTunings(kp, ki, kd);

		kp = (float) *(&config[i+=4]);
		ki = (float) *(&config[i+=4]);
		kd = (float) *(&config[i+=4]);
		angle_z.setTunings(kp, ki, kd);

		kp = (float) *(&config[i+=4]);
		ki = (float) *(&config[i+=4]);
		kd = (float) *(&config[i+=4]);
		gforce.setTunings(kp, ki, kd);

		float t = (float) *(&config[i+=4]);
		imu.setBeta(t);

		//6 * 2 bytes = 12 bytes total for accel + gyro calibration
		int16_t mpuCalibration[6];
		mpuCalibration[0] = (uint16_t) *(&config[i+=2]);
		mpuCalibration[1] = (uint16_t) *(&config[i+=2]);
		mpuCalibration[2] = (uint16_t) *(&config[i+=2]);
		mpuCalibration[3] = (uint16_t) *(&config[i+=2]);
		mpuCalibration[4] = (uint16_t) *(&config[i+=2]);
		mpuCalibration[5] = (uint16_t) *(&config[i+=2]);
		mpu6050.setCalibration(mpuCalibration);

		//3 * 4 bytes = 12 bytes total for magnetometer calibration
		vector_t magCalibration;
		magCalibration.x = (float) *(&config[i+=4]);
		magCalibration.y = (float) *(&config[i+=4]);
		magCalibration.z = (float) *(&config[i+=4]);
		hmc5883l.setCalibration(magCalibration);

		sendStatus("Load Config   ", 14);
	}
	else {
		sendStatus("Load Defaults ", 14);
	}
}

void Chiindii::saveConfig(){
	float kp, ki, kd;
	uint8_t config[116];

	uint8_t i = 0;
	config[i++] = 0x42;
	config[i++] = 0x42;

	rate_x.getTunings(&kp, &ki, &kd);


// 	cli();
// 	wdt_disable();
//
// 	eeprom_update_float((float*) (EEPROM_OFFSET + 0), rate_x.getKp());
// 	eeprom_update_float((float*) (EEPROM_OFFSET + 4), rate_x.getKi());
// 	eeprom_update_float((float*) (EEPROM_OFFSET + 8), rate_x.getKd());
//
// 	eeprom_update_float((float*) (EEPROM_OFFSET + 12), rate_y.getKp());
// 	eeprom_update_float((float*) (EEPROM_OFFSET + 16), rate_y.getKi());
// 	eeprom_update_float((float*) (EEPROM_OFFSET + 20), rate_y.getKd());
//
// 	eeprom_update_float((float*) (EEPROM_OFFSET + 24), rate_z.getKp());
// 	eeprom_update_float((float*) (EEPROM_OFFSET + 28), rate_z.getKi());
// 	eeprom_update_float((float*) (EEPROM_OFFSET + 32), rate_z.getKd());
//
// 	eeprom_update_float((float*) (EEPROM_OFFSET + 36), angle_x.getKp());
// 	eeprom_update_float((float*) (EEPROM_OFFSET + 40), angle_x.getKi());
// 	eeprom_update_float((float*) (EEPROM_OFFSET + 44), angle_x.getKd());
//
// 	eeprom_update_float((float*) (EEPROM_OFFSET + 48), angle_y.getKp());
// 	eeprom_update_float((float*) (EEPROM_OFFSET + 52), angle_y.getKi());
// 	eeprom_update_float((float*) (EEPROM_OFFSET + 56), angle_y.getKd());
//
// 	eeprom_update_float((float*) (EEPROM_OFFSET + 60), angle_z.getKp());
// 	eeprom_update_float((float*) (EEPROM_OFFSET + 64), angle_z.getKi());
// 	eeprom_update_float((float*) (EEPROM_OFFSET + 68), angle_z.getKd());
//
// 	eeprom_update_float((float*) (EEPROM_OFFSET + 72), gforce.getKp());
// 	eeprom_update_float((float*) (EEPROM_OFFSET + 76), gforce.getKi());
// 	eeprom_update_float((float*) (EEPROM_OFFSET + 80), gforce.getKd());
//
// #if defined MAHONY
// #elif defined MADGWICK
// 	eeprom_update_float((float*) (EEPROM_OFFSET + 84), imu.getBeta());
// #endif
//
// 	eeprom_update_block(mpu6050.getCalibration(), (void*) (EEPROM_OFFSET + 88), 12);
//
// 	//Write the magic value to say that we have written valid bytes
// 	eeprom_update_byte((uint8_t*) EEPROM_MAGIC, 0x42);
//
// 	wdt_enable(WDTO_120MS);
// 	sei();
//
// 	sendStatus("Save EEPROM   ", 14);
}
