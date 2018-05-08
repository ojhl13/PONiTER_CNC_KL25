/*
 * uart.h
 *
 *  Created on: Mar 8, 2018
 *      Author: Fernando
 */

#ifndef UART_H_
#define UART_H_



void Global_UART0_init(void);
void UART0_init(void);
void Receiver(void);
unsigned char MOTOR_ON(void);
unsigned char MOTOR_OFF(void);
unsigned char DIR_CW(void);
unsigned char DIR_CCW(void);
unsigned char STEPCW(void);
unsigned char RPS(void);
unsigned char TEMPLIMIT(void);
void DoneMessage(void);
void OverTmp(void);
unsigned char getOn(void);
void UART0_IRQHandler(void);
unsigned char GetX(unsigned char index);
unsigned char GetY(unsigned char index);
unsigned char getFlag(void);
unsigned char getindex (void);


#endif /* UART_H_ */
