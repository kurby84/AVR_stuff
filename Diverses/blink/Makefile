CC=avr-gcc
CFLAGS=-g -Os -Wall -mcall-prologues -mmcu=atmega8
OBJ2HEX=avr-objcopy 
UISP=uisp 
TARGET=blink

program : $(TARGET).hex
	$(UISP) -dprog=stk200 -dlpt=/dev/parport0 --erase
	$(UISP) -dprog=stk200 -dlpt=/dev/parport0 --upload \
		if=$(TARGET).hex -v=2
%.obj : %.o
	$(CC) $(CFLAGS) $< -o $@

%.hex : %.obj
	$(OBJ2HEX) -R .eeprom -O ihex $< $@

clean :
	rm -f *.hex *.obj *.o


