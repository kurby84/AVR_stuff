# makefile, written by guido socher
MCU=atmega8
# MCU=attiny2313
CC=avr-gcc
OBJCOPY=avr-objcopy
# optimize for size:
#CFLAGS=-g -I /usr/include -mmcu=$(MCU) -Wall -Wstrict-prototypes -Os -mcall-prologues
CFLAGS= -I /usr/include -mmcu=$(MCU) -Wall
#-------------------
all: ledtest.hex
#-------------------
help: 
	@echo "Usage: make [all]|load|load_pre|rdfuses|wrfuse1mhz|wrfuse4mhz|wrfuse8mhz|wrfusecrystal"
	@echo "Warning: you will not be able to undo wrfusecrystal unless you connect an"
	@echo "         external crystal! uC is dead after wrfusecrystal if you do not"
	@echo "         have an external crystal."
#-------------------
ledtest.hex : ledtest.out
	$(OBJCOPY) -R .eeprom -O ihex ledtest.out ledtest.hex
ledtest.out : ledtest.o
	$(CC) $(CFLAGS) -o ledtest.out -Wl,-Map,ledtest.map ledtest.o
ledtest.o : ledtest.c
	$(CC) $(CFLAGS) -c ledtest.c -Os
# you need to erase first before loading the program.
# load (program) the software into the eeprom:
load: ledtest.hex
	uisp -dlpt=/dev/parport0 --erase  -dprog=stk200
	uisp -dlpt=/dev/parport0 --upload if=ledtest.hex -dprog=stk200  -v=3 --hash=32
# here is a pre-compiled version in case you have trouble with
# your development environment
load_pre: ledtest_pre.hex
	uisp -dlpt=/dev/parport0 --erase  -dprog=stk200
	uisp -dlpt=/dev/parport0 --upload if=ledtest_pre.hex -dprog=stk200 -dno-poll -v=3 --hash=32
#-------------------
# fuse byte settings:
#  Atmel AVR ATmega8 
#  Fuse Low Byte      = 0xe1 (1MHz internal), 0xe3 (4MHz internal), 0xe4 (8MHz internal)
#  Fuse High Byte     = 0xd9 
#  Factory default is 0xe1 for low byte and 0xd9 for high byte
# Check this with make rdfuses
rdfuses:
	uisp -dlpt=/dev/parport0 -dprog=stk200 --rd_fuses
# use internal RC oscillator 1 Mhz
wrfuse1mhz:
	uisp -dlpt=/dev/parport0 -dprog=stk200 --wr_fuse_l=0xe1
# use internal RC oscillator 4 Mhz
wrfuse4mhz:
	uisp -dlpt=/dev/parport0 -dprog=stk200 --wr_fuse_l=0xe3
# use internal RC oscillator 8 Mhz
wrfuse8mhz:
	uisp -dlpt=/dev/parport0 -dprog=stk200 --wr_fuse_l=0xe4
# use external 3-8 Mhz crystal
# Warning: you can not reset this to intenal unless you connect a crystal!!
wrfusecrystal:
	uisp -dlpt=/dev/parport0 -dprog=stk200 --wr_fuse_l=0xee
#-------------------
clean:
	rm -f *.o *.map *.out *t.hex
#-------------------
