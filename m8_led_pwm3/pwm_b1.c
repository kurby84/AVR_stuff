#define F_CPU 1000000  //1MHz
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void){
    TCCR1A = (1 << WGM10) | (1 << COM1A1);
    TCCR1B = (1 << CS10) | (1 << WGM12);
    DDRB = 0xFF;
    sei(); //enable global interrupts
    PORTB = 0b00000000;  // disable Port B

    while(1)
    {
        int i;
        for(i=0;i<=255;i=i+5)
        {
            OCR1A=i;
            _delay_ms(100);  // keep this light intensity for 100
                             // ms
        }

        for(i=255;i>0;i=i-5)
        {
            OCR1A=i;
            _delay_ms(100);
        }
    }
}
