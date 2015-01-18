TARGET = blink
MCU    = attiny2313
CC     = avr-gcc
 
CFLAGS  =-mmcu=$(MCU) -Wall 
LDFLAGS =-mmcu=$(MCU)

$(TARGET): $(TARGET).o

$(TARGET).hex : $(TARGET)
	 avr-objcopy -j .data -j .text -O ihex $< $@

load: $(TARGET).hex
	avrdude -p t2313 -c avr910 -U flash:w:$(TARGET).hex -v

clean:
	rm -f *.o  *.hex $(TARGET)
