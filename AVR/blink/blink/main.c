/*
 * LED_Blink_Board.c
 *
 * Created: 26.09.2015 19:35:02
 *  Author: User
 */ 
#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB = 0x01;
	PORTB = 0;
	
    while(1)
    {
        PORTB = 0x01;
		_delay_ms(500); 
		PORTB = 0;
		_delay_ms(500);
    }
}
