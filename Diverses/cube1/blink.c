/*
 *  blink.c
 *  ATtiny2313 mit 1 MHz
 *  PORTB wird ueber ein Timer alle 0.263s ein- und ausgeschaltet. Das entspricht 3.81Hz
 */

#include <avr/io.h>
#include <avr/interrupt.h>

ISR (TIMER0_OVF_vect)
{
  PORTB =~ PORTB; // PORTB inventieren
}

int main()
{
  /*
	A: PD5
	B: PD4
	C: PD3

	9: PD6
	1: PB0
	
	1 -> GND
	0 -> +
  */
  DDRD  = 0xFF; // PORTD als Ausgang schalten
  DDRB  = 0xFF; // PORTB als Ausgang schalten
  PORTB = 0x00; // Alle Ausgaenge auf 0 schalten
  PORTD = 0x00;
  PORTD = (1 << PD4);

  // PORTD = (1 << PD4);
  PORTB = 0xFF;
  PORTD = (1 << PD6);

  // PORTB = 0xFF; // Alle Ausgaenge auf 0 schalten
  // PORTB =~ PORTB;
  //PORTB = (0 << PB1);

  TCCR0B |= (1 << CS02) | (1 << CS00); // Prescaler auf 1024 stellen
  TIMSK  |= (1 << TOIE0);              // Timer 0 Overflow Interrupt enable

  sei(); // Interrupts einschalten

  for(;;); //ever
}
