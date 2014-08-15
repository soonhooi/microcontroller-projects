#ifndef SHIFTREGISTER_H
#define SHIFTREGISTER_H

#include <avr/io.h>

namespace digitalcave {
/*
	 * Shift register library - this is designed for 74595 and compatible shift registers.
	 * You need a minimum of two wires to control a shift register, or three wires to control a shift register with latch.
	 * This library uses MOSI, SCK, and SS.  (SS is not actually used but must be held high for interrupts to work properly).
	 *
	 * 74HC595 pinout:
	 * Pin 1 - 7: Outputs B - H
	 * Pin 8: GND
	 * Pin 9: Output H' (chain this to pin 14 if you are linking multiple registers)
	 * Pin 10: /Clear (connect to VCC, or the port/pin defined in initClear)
	 * Pin 11: Clock (connect to SPI SCK, B5 on 168 series)
	 * Pin 12: Latch (connect to port/pin as defined in initLatch)
	 * Pin 13: /Output Enable (Connect to GND, or the port/pin defined in initEnable)
	 * Pin 14: Data (connect to SPI MOSI, B3 on 168 series or previous shift register if chaining)
	 * Pin 15: Output A
	 * Pin 16: VCC
	 *
	 * STPIC6D595 pinout:
	 * Pin 1: VCC
	 * Pin 2: Data (connect to SPI MOSI, B3 on 168 series or previous shift register if chaining)
	 * Pin 3 - 6: Drain 0 - 3
	 * Pin 7: /Clear (connect to VCC, or the port/pin defined in initClear)
	 * Pin 8: /Output Enable (Connect to GND, or the port/pin defined in initEnable)
	 * Pin 9: Serial Output (chain this to pin 14 if you are linking multiple registers)
	 * Pin 10: Latch (connect to port/pin defined in setLatch)
	 * Pin 11 - 14: Drain 4 - 7
	 * Pin 15: Clock (connect to SPI SCK, B5 on 168 series)
	 * Pin 16: GND
	 *
	 * 74HC164 pinout:
	 * Pin 1: Data (connect to SPI MOSI, B3 on 168 series or previous shift register if chaining)
	 * Pin 2: Connect to Pin 1 or VCC
	 * Pin 3 - 6: Output A - D
	 * Pin 7: GND
	 * Pin 8: Clock (connect to SPI SCK, B5 on 168 series)
	 * Pin 9: /Clear (connect to VCC, or the port/pin defined in initClear)
	 * Pin 10 - 13: Output E - H
	 * Pin 14: VCC
	 */
	class ShiftRegister {

		private:
			volatile uint8_t *enable_port;
			uint8_t enable_bv;
			volatile uint8_t *clear_port;
			uint8_t clear_bv;
			volatile uint8_t *spi_port;
			uint8_t mosi_bv;
			uint8_t sclk_bv;

		public:
		
			ShiftRegister(volatile uint8_t *spi_port, uint8_t mosi_pin, uint8_t sclk_pin);
	
			void setCallback(void (*callback)());
		
			/*
			 * Configures latching after the last byte has been written.
			 */
			void initLatch(volatile uint8_t *port, uint8_t pin);
	
			/*
			 * Configures output enable.
			 */
			void initEnable(volatile uint8_t *port, uint8_t pin);
	
			/*
			 * Configures clear.
			 */
			void initClear(volatile uint8_t *port, uint8_t pin);
	
			/*
			 * Initializes SPI.
			 * This is optional only if SPI is initialized elsewhere.
			 */
			void initSpi();

			/*
			 * Shifts all the bytes in the byte array into the shift register chain, latching at the end if latch is configured.
			 */
			void shift(uint8_t b[], uint8_t sz);
		
			/*
			 * Returns 1 if it's clear to send; 0 if bytes are still being transmitted.
			 */
			uint8_t cts();
	
			/*
			 * Enables output, if OE is configured.
			 */	
			void enable();

			/*
			 * Disables output, if OE is configured.
			 */	
			void disable();
	
			/*
			 * Clears the register, if clear is configured.
			 */
			void clear();
	};
}
#endif
