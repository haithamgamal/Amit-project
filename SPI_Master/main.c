/*
 * main.c
 *
 *  Created on: Jan 16, 2021
 *      Author: HAITHAM
 */

#include <avr/io.h>
#include <stdlib.h>
#include "SPI.h"
#include "LSTD_Types.h"
#include "LUTILS.h"
#include "MUART_Private.h"
#include "MUART_Interface.h"
#include "MUART_Config.h"
#include <util/delay.h>
#include "UART.h"
#include "SPI_UART.h"
int main(void)
{    DDRC = 0XFF;
     PORTC =0X00 ;
	 UART_init(9600);
	 char arr[10];
	 SPI_init(SPI_MASTER);
	while(1)
	{
		SPI_UART_TR_string(arr);

		if(comparestring(arr, "onled1"))
						{
							PORTC |= 0X01;   // LIGHTING LED1
						}
						else if(comparestring(arr, "offled1"))
						{
							PORTC &= ~(0x01);
						}
						else if(comparestring(arr, "onled2"))
						{
							PORTC |= 0X02;
						}
						else if(comparestring(arr, "offled2"))
						{
							PORTC &= ~(0x02);
						}




	}

}
