/*
 * UART.c
 *
 *  Created on: Jan 17, 2021
 *      Author: HAITHAM
 */
#include <avr/io.h>
#include <stdlib.h>
char comparestring(char arr1[10], char arr2[10])
{
	int i=0 ;
	char flag ;
	while(arr2[i]!='\0')      //x
	{
		if(arr1[i]==arr2[i])
		{
			flag=1;
		}
		else flag =0;
		i++;
	}
	return flag ;
}

void UART_init(long BaudRate)
{
	UCSRB = (1<<RXEN) | (1<<TXEN) ;
	UCSRC = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);

	UBRRL = (unsigned char)(((F_CPU)/(16*BaudRate))-1)  ;
}

void UART_send_byte(char byte)
{
	while(!(UCSRA &(1<<UDRE))); // while shift register flag !=1 (not empty)
	UDR= byte ;
}

void UART_send_string(char* ptr)
{
	int i ;
	while(ptr[i] != '\0')
	{
		UART_send_byte(ptr[i]);
		i++ ;
	}
	UART_send_byte(ptr[i]);
}

char UART_receive_byte(void)
{
	while((UCSRA & (1<<RXC))== 0);
	return UDR ;
}
void UART_receive_string(char* ptr)
{
	int i=0 ;
	ptr[i]= UART_receive_byte();
	while(ptr[i]!='#')
	{
		i++ ;
		ptr[i]= UART_receive_byte();
	}
	ptr[i]='\0';
}

