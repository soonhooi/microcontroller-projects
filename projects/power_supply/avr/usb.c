#include "usb.h"

using namespace digitalcave;

extern Channel channels[CHANNEL_COUNT];
extern Display display;
extern State state;

void usb_send_measurement(uint8_t message, uint8_t channel, uint16_t voltage, uint16_t current){
	uint8_t tx_buffer[6];
	tx_buffer[0] = message;				//Message type
	tx_buffer[1] = channel;				//Channel number
	tx_buffer[2] = (voltage >> 8) & 0xFF;
	tx_buffer[3] = voltage & 0xFF;
	tx_buffer[4] = (current >> 8) & 0xFF;
	tx_buffer[5] = current & 0xFF;

	usb_rawhid_send(tx_buffer, 6);
}

void usb_send_startup(uint8_t message, uint8_t channel, uint8_t target, int16_t startup){
	uint8_t tx_buffer[5];
	tx_buffer[0] = message;				//Message type
	tx_buffer[1] = channel;				//Channel number
	tx_buffer[2] = target;
	tx_buffer[3] = (startup >> 8) & 0xFF;
	tx_buffer[4] = startup & 0xFF;

	usb_rawhid_send(tx_buffer, 5);
}

void usb_send_calibration(uint8_t message, uint8_t channel, uint8_t target, uint8_t index, calibration_t calibration){
	uint8_t tx_buffer[10];
	tx_buffer[0] = message;				//Message type
	tx_buffer[1] = channel;				//Channel number
	tx_buffer[2] = target;				//Voltage or Current
	tx_buffer[3] = index;				//Calibration index
	tx_buffer[4] = (calibration.dac >> 8) & 0xFF;
	tx_buffer[5] = calibration.dac & 0xFF;
	tx_buffer[6] = (calibration.adc >> 8) & 0xFF;
	tx_buffer[7] = calibration.adc & 0xFF;
	tx_buffer[8] = (calibration.adjusted >> 8) & 0xFF;
	tx_buffer[9] = calibration.adjusted & 0xFF;
	usb_rawhid_send(tx_buffer, 10);
}

void usb_send_dac_confirmation(uint8_t dac_number){
	uint8_t tx_buffer[2];
	tx_buffer[0] = MESSAGE_SET_DAC_ADDRESS;				//Message type
	tx_buffer[1] = dac_number;									//Channel number

	usb_rawhid_send(tx_buffer, 2);
}

void usb_dispatch(){
	uint8_t rx_buffer[10];
	uint8_t length = usb_rawhid_recv(rx_buffer, 0);
	
	if (length >= 2){
		switch(rx_buffer[0]){
			case MESSAGE_CHANNELS: {
				uint8_t tx_buffer[2];
				tx_buffer[0] = MESSAGE_CHANNELS;
				tx_buffer[1] = CHANNEL_COUNT;
				usb_rawhid_send(tx_buffer, 3);
				break;
			}
			case MESSAGE_GET_CHANNEL_INFO: {
				uint8_t channel = rx_buffer[1];
				uint8_t tx_buffer[6];
				tx_buffer[0] = MESSAGE_GET_CHANNEL_INFO;
				tx_buffer[1] = channel;
				int16_t voltage_limit = channels[channel].get_voltage_limit();
				int16_t current_limit = channels[channel].get_current_limit();
				tx_buffer[2] = (voltage_limit >> 8) & 0xFF;
				tx_buffer[3] = voltage_limit & 0xFF;
				tx_buffer[4] = (current_limit >> 8) & 0xFF;
				tx_buffer[5] = current_limit & 0xFF;
				usb_rawhid_send(tx_buffer, 6);
				break;
			}
			case MESSAGE_GET_ACTUAL: {
				uint8_t channel = rx_buffer[1];
				if (channel < CHANNEL_COUNT){
					usb_send_measurement(MESSAGE_GET_ACTUAL, channel, channels[channel].get_voltage_actual(), channels[channel].get_current_actual());
				}
				break;
			}
			case MESSAGE_GET_ACTUAL_RAW: {
				uint8_t channel = rx_buffer[1];
				if (channel < CHANNEL_COUNT){
					usb_send_measurement(MESSAGE_GET_ACTUAL_RAW, channel, channels[channel].get_voltage_actual_raw(), channels[channel].get_current_actual_raw());
				}
				break;
			}
			case MESSAGE_GET_SETPOINT: {
				uint8_t channel = rx_buffer[1];
				if (channel < CHANNEL_COUNT){
					usb_send_measurement(MESSAGE_GET_SETPOINT, channel, channels[channel].get_voltage_setpoint(), channels[channel].get_current_setpoint());
				}
				break;
			}
			case MESSAGE_GET_SETPOINT_RAW: {
				uint8_t channel = rx_buffer[1];
				if (channel < CHANNEL_COUNT){
					usb_send_measurement(MESSAGE_GET_SETPOINT_RAW, channel, channels[channel].get_voltage_setpoint_raw(), channels[channel].get_current_setpoint_raw());
				}
				break;
			}
			case MESSAGE_SET_SETPOINT: {
				uint8_t channel = rx_buffer[1];
				if (channel < CHANNEL_COUNT){
					channels[channel].set_voltage_setpoint((int16_t) ((rx_buffer[2] << 8) + rx_buffer[3]));
					channels[channel].set_current_setpoint((int16_t) ((rx_buffer[4] << 8) + rx_buffer[5]));
					usb_send_measurement(MESSAGE_SET_SETPOINT, channel, channels[channel].get_voltage_setpoint(), channels[channel].get_current_setpoint());
				}
				break;
			}
			case MESSAGE_SET_SETPOINT_RAW: {
				uint8_t channel = rx_buffer[1];
				if (channel < CHANNEL_COUNT){
					channels[channel].set_voltage_setpoint_raw((rx_buffer[2] << 8) + rx_buffer[3]);
					channels[channel].set_current_setpoint_raw((rx_buffer[4] << 8) + rx_buffer[5]);
					usb_send_measurement(MESSAGE_SET_SETPOINT_RAW, channel, channels[channel].get_voltage_setpoint_raw(), channels[channel].get_current_setpoint_raw());
				}
				break;
			}
			case MESSAGE_GET_CALIBRATION: {
				uint8_t channel = rx_buffer[1];
				uint8_t target = rx_buffer[2];
				uint8_t index = rx_buffer[3];
				calibration_t calibration;
				switch(target){
					case TARGET_VOLTAGE: calibration = channels[channel].get_calibration_voltage(index); break;
					case TARGET_CURRENT: calibration = channels[channel].get_calibration_current(index); break;
				}
				
				usb_send_calibration(MESSAGE_SET_CALIBRATION, channel, target, index, calibration);
				break;
			}
			case MESSAGE_SET_CALIBRATION: {
				uint8_t channel = rx_buffer[1];
				uint8_t target = rx_buffer[2];
				uint8_t index = rx_buffer[3];
				calibration_t calibration;
				calibration.dac = (rx_buffer[4] << 8) + rx_buffer[5];
				calibration.adc = (rx_buffer[6] << 8) + rx_buffer[7];
				calibration.adjusted = (rx_buffer[8] << 8) + rx_buffer[9];
				switch(target){
					case TARGET_VOLTAGE: channels[channel].set_calibration_voltage(index, calibration); break;
					case TARGET_CURRENT: channels[channel].set_calibration_current(index, calibration); break;
				}
				channels[channel].save_calibration();
				
				usb_send_calibration(MESSAGE_SET_CALIBRATION, channel, target, index, calibration);
				break;
			}
			case MESSAGE_GET_STARTUP_VALUE: {
				uint8_t channel = rx_buffer[1];
				uint8_t target = rx_buffer[2];
				int16_t startup = 0;
				switch(target){
					case TARGET_VOLTAGE: startup = channels[channel].get_voltage_startup(); break;
					case TARGET_CURRENT: startup = channels[channel].get_current_startup(); break;
				}
				usb_send_startup(MESSAGE_GET_STARTUP_VALUE, channel, target, startup);
				break;
			}
			case MESSAGE_SET_STARTUP_VALUE: {
				uint8_t channel = rx_buffer[1];
				uint8_t target = rx_buffer[2];
				int16_t startup = (rx_buffer[3] << 8) + rx_buffer[4];
				switch(target){
					case TARGET_VOLTAGE: channels[channel].set_voltage_startup(startup); break;
					case TARGET_CURRENT: channels[channel].set_current_startup(startup); break;
				}
				usb_send_startup(MESSAGE_SET_STARTUP_VALUE, channel, target, startup);
				break;
			}
			case MESSAGE_SET_DAC_ADDRESS: {
				uint8_t old_dac_number = rx_buffer[1];
				uint8_t new_dac_number = rx_buffer[2];
				if (old_dac_number > 2 || new_dac_number > 2){
					usb_send_dac_confirmation(0xFF);
					break;
				}
				
				DDRB |= _BV(PORTB0);
				PORTB |= _BV(PORTB0);
				
				
				//This is a hack.
				// The MCP4728 uses a weird, non-standard I2C message to set the address bits.  It uses LDAC as 
				// a selector, and this must be toggled from high to low during the low pulse of the 8th bit
				// in the clock of byte 2.  Obviously our I2C library does not support this, so we need to fake
				// it.  Start the I2C command with the option 'NO BLOCK', and delay for a specific amount of
				// time.  After the delay, bring the LDAC line low.  Timing is critical here; from experiments
				// I found that the right time is just under 40us, but this may differ a bit.  It is recommended
				// that you use a logic probe on SDA, SCL, and LDAC to verify the timing, and adjust this delay
				// as needed.
				// The good news is that this only needs to happen once (per DAC).
				uint8_t message[3];
				message[0] = DAC_COMMAND_ADDRESS | old_dac_number << 2 | 1;		//Command 0x60 + current address (left shifted 2) + 1
				message[1] = DAC_COMMAND_ADDRESS | new_dac_number << 2 | 2;		//Command 0x60 + current address (left shifted 2) + 2
				message[2] = DAC_COMMAND_ADDRESS | new_dac_number << 2 | 3;		//Command 0x60 + new address (left shifted 2) + 3
				twi_write_to(DAC_ADDRESS_0 + old_dac_number, message, 3, TWI_NO_BLOCK, TWI_STOP);
				
				_delay_us(39.6);
				PORTB &= ~_BV(PORTB0);
				
				_delay_ms(100);
				
				usb_send_dac_confirmation(new_dac_number);
				
				DDRB &= ~_BV(PORTB0);
				break;
			}
			case MESSAGE_SET_AREF: {
				uint8_t dac_number = rx_buffer[1];
				uint8_t dac_channel = rx_buffer[2];
				
				uint8_t message[3];
				message[0] = DAC_COMMAND_REGISTER_EEPROM | (dac_channel << 1);		//Single write with EEPROM persist
				message[1] = 0x9F;	//First nibble is [VREF,PD1,PD0,Gx].  Set VREF and Gx high.  Second nibble is all high (max value)
				message[2] = 0xFF;	//this byte is all high (max value)
				twi_write_to(DAC_ADDRESS_0 + dac_number, message, 3, TWI_BLOCK, TWI_STOP);
				
				usb_send_dac_confirmation(dac_number);
				break;
			}
			
			case MESSAGE_BOOTLOADER_JUMP: {
				display.get_char_display().clear();
				//TODO Figure out why we can't show text at this point...
				//display.get_char_display().write_text(0, 0, "     DFU Mode       ", DISPLAY_COLS);
				//display.get_char_display().refresh();
				_delay_ms(1000);	//Wait for the client python program to exit
				bootloader_jump();
				break;
			}
		}
	}
}