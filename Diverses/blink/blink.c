#define F_CPU 10000000UL
#include <avr/io.h>
#include <avr/delay.h>

void delayms(uint16_t millis) {
  uint16_t loop;
  while ( millis ) {
    _delay_ms(1);
    millis--;
  }
}

int main(void) {
  DDRB |= 1<<PC5; /* set PB0 to output */
  while(1) {
    PORTB &= ~(1<<PC5); /* LED on */
    delayms(100);
//    PORTB |= 1<<PC5; /* LED off */
  //  delayms(900);
  }
  return 0;
}

