/*
 * SPI.h
 *
 *  Created on: Jan 16, 2021
 *      Author: HAITHAM
 */

#ifndef SPI_H_
#define SPI_H_

#define   SS    4
#define   SCK   7
#define   MOSI  5
#define   MISO  6
#define   SPI_MASTER    1
#define   SPI_SLAVE     0

#define   SPI_PS_4      1
#define   SPI_PS_16     2
#define   SPI_PS_64     3
#define   SPI_PS_128    4
#define   SPI_PS_2      5
#define   SPI_PS_8      6
#define   SPI_PS_32     7


void SPI_MASTER_send(char );
void SPI_init(int ) ;
void SPI_MASTER_send_str(char* );
void SPI_MASTER_send_num(int );
char SPI_SLAVE_receive(void) ;
void SPI_receive_str(char* ptr);


#endif /* SPI_H_ */
