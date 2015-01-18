/*
 *  blink.c
 *  ATtiny2313 mit 1 MHz
 *  PORTB wird ueber ein Timer alle 0.263s ein- und ausgeschaltet. Das entspricht 3.81Hz
 */

#include <avr/io.h>
#include <avr/interrupt.h>

// ISR (SIG_TIMER0_OVF)
ISR (SIG_OVERFLOW0)
{
  PORTB =~ PORTB; // PORTB inventieren
}

int main()
{
  DDRB  = 0xFF; // PORTB als Ausgang schalten
  PORTB = 0x00; // Alle Ausgaenge auf 0 schalten

  TCCR0B |= (1 << CS02) | (1 << CS00); //Prescaler auf 1024 stellen
  TIMSK  |= (1 << TOIE0);              // Timer 0 Overflow Interrupt enable

  sei(); // Interrupts einschalten

  for(;;); //ever
}
