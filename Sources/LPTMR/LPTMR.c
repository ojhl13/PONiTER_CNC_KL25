/*
 * LPTMR.c
 *
 *  Created on: Apr 8, 2018
 *      Author: Fernando
 */

#include "derivative.h" /* include peripheral declarations */
#include "LPTMR.h"

unsigned char times_up =0;

//Set Clock for LPTMR
void LPTMR_Init(void)
{
	SIM_SCGC5 |= 1<<0;
	LPTMR0_CMR=1000;
	LPTMR0_PSR=0b00000101;	
	LPTMR0_CSR=0b01000001;	//b6:hab local de interrrupciones, b0: timer enable
}

void LPTimer_IRQHandler()
{
	LPTMR0_CSR |= (1<<7);
	times_up=1;
}

unsigned char LPTMR_getFlag()
{
	return times_up;	
}

void LPTMR_set_CMR(unsigned long cmr)
{
	LPTMR0_CMR=cmr;
}

void LPTMR_setFlag()
{
	times_up=0;
}


