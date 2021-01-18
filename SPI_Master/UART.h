/*
 * UART.h
 *
 *  Created on: Jan 17, 2021
 *      Author: HAITHAM
 */

#ifndef UART_H_
#define UART_H_

char comparestring(char arr1[10], char arr2[10]);
void UART_init(long BaudRate);
void UART_send_byte(char byte);
void UART_send_string(char* ptr);
char UART_receive_byt(void);
void UART_receive_string(char* ptr);

#endif /* UART_H_ */
