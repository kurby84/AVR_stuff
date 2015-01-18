TARGET = blink
MCU    = attiny2313
CC     = avr-gcc
 
CFLAGS  =-mmcu=$(MCU) -Wall -O2
LDFLAGS =-mmcu=$(MCU)

$(TARGET): $(TARGET).o

$(TARGET).hex : $(TARGET)
	 avr-objcopy -j .data -j .text -O ihex $< $@

load: $(TARGET).hex
	avrdude -p t2313 -c avrispmkII -P usb -U flash:w:$(TARGET).hex -v

clean:
	rm -f *.o  *.hex $(TARGET)
