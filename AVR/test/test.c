#ifndef F_CPU
#define F_CPU 8000000UL // or whatever may be your frequency
#endif

#include <avr/io.h>
#include <util/delay.h>                // for _delay_ms()
  
int main(void)
{
    DDRB = 0x01;                       // initialize port B
    PORTB = 0;
    while(1)
    {
        // LED on
        PORTB = 0x01;            // PC0 = High = Vcc          
        _delay_ms(500);                // wait 500 milliseconds
        
        //LED off
        PORTB = 0;            // PC0 = Low = 0v
        _delay_ms(500);                // wait 500 milliseconds
    }
}
