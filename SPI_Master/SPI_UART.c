/*
 * SPI_UART.c
 *
 *  Created on: Jan 17, 2021
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
void SPI_UART_TR_string(char* ptr)
{
	int i=0 ;
	ptr[i]= UART_receive_byte();
	SPI_MASTER_send(ptr[i]);
			_delay_ms(10);
	while(ptr[i]!='#')
	{
		i++ ;
		ptr[i]= UART_receive_byte();
		SPI_MASTER_send(ptr[i]);
		_delay_ms(10);
	}
	ptr[i]='\0';
}

