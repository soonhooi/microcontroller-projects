/*
 * Driver for HD44780 in 4 bit mode using direct pin access.
 */

#ifndef HD44780_DIRECT_4BIT_H
#define HD44780_DIRECT_4BIT_H

#include <avr/io.h>
#include <stdlib.h>

#include "Hd44780.h"

namespace digitalcave {

	class Hd44780_Direct : public Hd44780 {
		private:
			uint8_t pin_rs;
			uint8_t pin_e;
			uint8_t pin_d4;
			uint8_t pin_d5;
			uint8_t pin_d6;
			uint8_t pin_d7;
			
			void write_nibble(uint8_t b, uint8_t mode);

			
		public:
			Hd44780_Direct(uint8_t function);
			
			Hd44780_Direct(uint8_t function, 
								uint8_t pin_rs,
								uint8_t pin_e,
								uint8_t pin_d4,
								uint8_t pin_d5,
								uint8_t pin_d6,
								uint8_t pin_d7);

			// Implementation of virtual functions declared in superclass
			virtual void write_byte(uint8_t b);
			virtual void write_command(uint8_t c);
	};
}

#endif