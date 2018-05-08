/*
 * GPIO.c
 *
 *  Created on: Mar 8, 2018
 *      Author: Fernando
 */

#include "derivative.h"
#include "GPIO.h"

void Global_GPIO_init(void)
{
	//To try my stuff
	SIM_SCGC5|=(1<<12); //CLK PORTD
	PORTD_PCR1=0x00000100;
	GPIOD_PDDR=0x00000002;
	GPIOD_PDOR=1<<1;
	
	//from the actual practice
	SIM_SCGC5|=0x00002C00; //CLK PB y PC
	PORTB_PCR0=0x00000100; //PTB0 GPIO
	PORTB_PCR1=0x00000100; //PTB1 GPIO
	PORTB_PCR2=0x00000100; //PTB2 GPIO
	PORTB_PCR3=0x00000100; //PTB3 GPIO
	PORTC_PCR2=0x00000100; //PTC2 GPIO
	
	
	GPIOB_PDDR=0x0000000F; //PTB0 a PTB3 como salida
	GPIOB_PDOR=0x00000000; // Valor inicial
}

void GPIO_Write_PB(unsigned char followed)
{
	GPIOB_PDOR=followed;
}

void GPIO_Write_PC(unsigned char followed)
{
	GPIOC_PDOR=followed;
}
