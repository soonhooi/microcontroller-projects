PROJECT=led_table
MMCU=atmega32u4
F_CPU=16000000
PROGRAMMER=dfu

# You can also define anything here and it will override 
# the definitions in variables.mk

CDEFS+=-DUSB_STRING_DESCRIPTOR_LENGTH=21 -DUSB_STR_MANUFACTURER=L\"Warren\ Janssens\" -DUSB_STR_PRODUCT=L\"Led\ Table\" -DUSB_VENDOR_ID=0x574a -DUSB_PRODUCT_ID=0x6c74
CDEFS+=-DWS281X_PORT=PORTB -DWS281X_PIN=2

include ../../../build/avr.mk
