#define F_CPU 1000000UL //Define the speed the clock is running at.  Used for the delay.h functions

#include <avr/io.h>     //Include the headers that handles Input/Output function for AVR chips
#include <util/delay.h> //Include the headers that allow for a delay function

//Prototypes
void Delay_ms(int cnt);
void init_io(void);

//Functions
void Delay_ms(int cnt)
{
  while(cnt-->0) _delay_ms(1);
}

void init_io(void)
{
  DDRB = (1 << PB0)|(1 << PB1)|(1<< PB2)|(1 << PB3)|(1 << PB4)|(1 << PB5)|(1 << PB6)|(1 << PB7); // Set LED pins as outputs
}

//Main Function
int main(void)
{
  init_io(); //Set up the pins that control the LEDs
  int i;     //Initialize variable to count through each LED

  // PORTB = 1;

  for (;;)   //Loop forever
  {
    for (i=0; i<8; i++)
    {
      PORTB |= (1 << i);  //Turn on LED i
      Delay_ms(1000);        //Wait 1 second
      PORTB = 0;          //Turn off all LEDs
    }
  }

  return 1;
}
