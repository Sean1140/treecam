/*
 * serial coms.c
 *
 * Created: 12/5/2017 2:07:25 PM
 * Author : Jim
 */ 

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/pinDefines.h>
#include <avr/macros.h>

void spi_init_slave (void)
{
	SPI_SS_DDR &= ~(1 << SPI_SS);                        /* set SS input */
	
	SPI_MOSI_DDR &= !(1 << SPI_MOSI);                   /* input on MOSI */
	SPI_MISO_DDR |= (1 << SPI_MISO);                   /* output on MISO */
	
	SPI_MOSI_PORT |= (1 << SPI_MOSI);                  /* pullup on MOSI */
	SPI_SCK_DDR &= ~(1 << SPI_SCK);                      /* input on SCK */
	
	SPCR |= (1 << SPE);                                        /* enable */
	
}

unsigned char spi_tranceiver (unsigned char data)
{
	SPDR = data;
	while(!(SPSR & (1<<SPIF) ));
	return(SPDR);
}

int main(void)
{
	spi_init_slave();
	unsigned char data = 0;
	while(1)
	{
		data = spi_tranceiver(data);
	}
}
