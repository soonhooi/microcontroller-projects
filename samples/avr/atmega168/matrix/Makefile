include ../../build/variables.mk

PROJECT=matrix
MMCU=atmega168
F_CPU=16000000
SOURCES=main.c lib/shiftcpp/shift.cpp lib/serial/serial.c lib/serial/serial_sync_rx.c lib/serial/serial_sync_tx.c
COMPILER=avr-g++


CFLAGS+=-D=NO_INTERRUPT_ENABLE

include ../../build/targets.mk
