#include "DrumMaster.h"

using namespace digitalcave;

//Pin assignments
#define MUX0						0
#define MUX1						1
#define MUX2						2
#define MUX3						3
#define DRAIN_EN					4
#define ADC_EN						5
#define ADC_INPUT					A14

//Constants
#define MIN_VALUE					10

State state;
Samples samples;
AudioControlSGTL5000 control;

ADC adc;


uint8_t readDrum(uint8_t channel){
	if (channel >= 8) return 0;		//TODO Remove on real board; breadboard MUX only have 8 inputs
	
	//Disable both MUXs
	digitalWriteFast(ADC_EN, 0);
	digitalWriteFast(DRAIN_EN, 0);
	
	delayMicroseconds(1);
	
	//Set channel
	digitalWriteFast(MUX0, channel & 0x01);
	digitalWriteFast(MUX1, channel & 0x02);
	digitalWriteFast(MUX2, channel & 0x04);
	digitalWriteFast(MUX3, channel & 0x08);

	delayMicroseconds(1);

	//Enable ADC MUX, read value, and disable MUX again
	digitalWriteFast(ADC_EN, 1);
	delayMicroseconds(1);
	uint8_t result = adc.analogRead(ADC_INPUT);
	digitalWriteFast(ADC_EN, 0);
	
	if (result > MIN_VALUE){
		//Reset the peak value
		digitalWriteFast(DRAIN_EN, 1);
	}
	
	return result;
}

int main(){
	//Audio shield SPI setup
	SPI.setMOSI(7);
	SPI.setMISO(12);
	SPI.setSCK(14);
	
	//Turn on the audio chip
	control.enable();
	control.volume(0.5);
	
	//Enable pins
	pinMode(MUX0, OUTPUT);
	pinMode(MUX1, OUTPUT);
	pinMode(MUX2, OUTPUT);
	pinMode(MUX3, OUTPUT);
	pinMode(DRAIN_EN, OUTPUT);
	pinMode(ADC_EN, OUTPUT);
	
	//Set up ADC
	adc.setResolution(8);

	if (!(SD.begin(10))) {
		// stop here, but print a message repetitively
		while (1) {
			Serial.println("Unable to access the SD card");
			delay(500);
		}
	}
	
	uint8_t channel = 0;
	while (1){
		state.poll();
		
		uint8_t value = readDrum(channel);
		if (value > MIN_VALUE){
			samples.play(channel, value);
		}
		channel = (channel + 1) & 0x0F;
	}
}

