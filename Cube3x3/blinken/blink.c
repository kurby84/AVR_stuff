/*
 *  blink.c
 *  ATtiny2313 mit 1 MHz
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#define BLINK_WECHSEL 20
int blinkcounter=0;


ISR (TIMER0_OVF_vect)
{
	blinkcounter++;
  if(blinkcounter<=BLINK_WECHSEL){
  	PORTD = PORTD ^ 1<<PD6; // port PD6 invertieren -> 9
  	PORTB = ~PORTB; // PORTB inventieren  -> 1-8
  }
  else if (blinkcounter<=2*BLINK_WECHSEL){
    PORTD = PORTD ^ 1<<PD4;
  	PORTD = PORTD ^ 1<<PD3;
  	PORTD = PORTD ^ 1<<PD5;
  }
  
  if (blinkcounter==BLINK_WECHSEL){
  	PORTD |=  1<<PD6;
 	PORTB = 0xFF; //alle 9 an schalten
	PORTD |=  1<<PD4; //mittlere Ebene ausschalten
  }
    if (blinkcounter==0){
	 PORTB = 0x00; // Alle Ausgaenge Port B auf 0 schalten
 	 PORTD = 0x00; // Alle Ausgaenge Port D auf 0 schalten
  }
  
  if (blinkcounter>=2*BLINK_WECHSEL){
  	blinkcounter=0;
  }
}

int main()
{
  /*
	A: PD5
	B: PD4
	C: PD3

	9: PD6
	1: PB0
	2: PB1
	...
	8: PB8
  */
  DDRD  = 0xFF; // PORTD als Ausgang schalten
  DDRB  = 0xFF; // PORTB als Ausgang schalten
  PORTB = 0x00; // Alle Ausgaenge Port B auf 0 schalten
  PORTD = 0x00; // Alle Ausgaenge Port D auf 0 schalten


  TCCR0B |= (1 << CS02) | (1 << CS00); // Prescaler auf 1024 stellen
  TIMSK  |= (1 << TOIE0);              // Timer 0 Overflow Interrupt enable

  sei(); // Interrupts einschalten

  for(;;); //ever
}
