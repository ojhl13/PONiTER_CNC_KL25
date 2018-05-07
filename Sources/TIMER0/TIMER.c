/*
 * TIMER.c
 *
 *  Created on: Apr 5, 2018
 *      Author: Fernando
 */

#include "derivative.h"
#include "TIMER.h"

unsigned char i;

void TPM_Init(void)
{
	i=0;
	//SIM_SCGC6|=(1<<27)+(1<<24);
	SIM_SCGC6|=(1<<24);
	SIM_SCGC5|=(1<<13)+(1<<12);//Port E
	//SIM_SCGC4|=(1<<10);
	//SIM_SOPT2|=(1<<26)+(3<<24);
	SIM_SOPT2|=(3<<24);
	PORTD_PCR1=1<<8;
	GPIOD_PDDR=0x00000002;
	
	
	MCG_C1|=1<<1;
	MCG_C2|=1;
	MCG_SC|=2<<1;
	TPM0_SC|=1<<3; //iniciar conteo
	//TPM0_C2SC|=(1<<6)+(1<<4)+(1<<2); //hab interrupciones
	TPM0_C2SC|=(1<<6)+(5<<2); //hab interrupciones
	
	NVIC_ICPR = (1<<17);  //Banderas TPM0
	NVIC_ISER = (1<<17);
	
	PORTE_PCR29=3<<8; //TPM0_CH2
	

}
void FTM0_IRQHandler()
{
	if(TPM0_C2SC|=(1<<7))
	{
		TPM0_C2SC|=1<<7;
		TPM0_C2V+=1000000;
		if((i%10)==0)GPIOD_PTOR=1<<1;
		if(i==254)i=0;
		i++;
		
	}
		
}


