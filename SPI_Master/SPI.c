/*
 * SPI.c
 *
 *  Created on: Jan 16, 2021
 *      Author: HAITHAM
 */
#include <avr/io.h>
#include <stdlib.h>
#include "SPI.h"


void SPI_init(int mode)
{   DDRC = 0XFF;
	if (mode == SPI_MASTER)
	{
		DDRB |= (1<<SS) | (1<<SCK) | (1<<MOSI);
		SPCR |= (1<<MSTR);
	}
	else
	{
		DDRB |= (1<<MISO);
	}

	SPCR |= (1<<SPE) | (1<<SPR0) | (1<<SPR1);

}

 void SPI_MASTER_send(char data)
 {
	 SPDR = data;
	 while(!(SPSR & (1<<SPIF)));
 }
 void SPI_MASTER_send_str(char* str)
 {
	 for(int i=0; str[i]!='\0';i++)
	 {
		 SPI_MASTER_send(str[i]);
	 }
 }
 void SPI_MASTER_send_num(int num)
 {
	 char str[10];
	 itoa(num,str,10);
	 SPI_MASTER_send_str( str);
 }

 char SPI_SLAVE_receive()
 {
	 while(!(SPSR & (1<<SPIF)));

	 return SPDR ;
 }

 void SPI_receive_str(char* ptr)
 {
	 int i=0 ;
	 	ptr[i]= SPI_SLAVE_receive();
	 	while(ptr[i]!='#')
	 	{
	 		i++ ;
	 		ptr[i]= SPI_SLAVE_receive();
	 	}
	 	ptr[i]='\0';
 }
