/*
 * UART.c
 *
 *  Created on: Mar 8, 2018
 *      Author: Fernando
 */

#include "derivative.h"
#include "UART.h"

#ifndef N
#define N 32
#endif

static unsigned char tmp[N];
static unsigned char i=0; 
static unsigned char dummie =0;
unsigned char done[6] = {'D', 'O', 'N', 'E', '\r' ,'\n'};
static unsigned char flag;
static unsigned char index;


void Global_UART0_init(void)
{
	SIM_SCGC4|=(1<<10); //CLK UART0
	SIM_SOPT2|=(1<<26); //CLK UART0
	SIM_SCGC5|=(1<<9); //CLK PORTA TX y RX
	PORTA_PCR1|=(2<<8); //PTA1 ALT2 UART0 TX
	PORTA_PCR2|=(2<<8); //PTA2 ATL2 UART0 RX
	NVIC_ICPR=(1<<12); //borrar banderas pendientes
	NVIC_ISER=(1<<12); //habilitar interrupciones de UART0
}

void UART0_init(void)
{
	flag =0;
	UART0_BDL=137;
	UART0_C2=(3<<2); //Enable Transmit and Recieve

}

void Receiver(void)
{
	UART0_C2=0x2C;
}



void DoneMessage(void)
{
	unsigned char i=0;
	do{
	do{}while(!(UART0_S1&(1<<7)));
	UART0_D=done[i++];
	}while(done[i]!=0);
}

unsigned char  converASCIII ( unsigned char * array){
	unsigned char result;
	result = ((*array)-0x30)*100;
	array++;
	result += ((*array)-0x30)*10;
	array++;
	result += ((*array)-0x30);
	return result;
}
void setFlag(void)
{
	flag=1;
}
unsigned char getFlag(void)
{
	return flag;
}
void setindex(void)
{
	index=i;
}
unsigned char getindex (void)
{
	return index;
}
unsigned char GetX(unsigned char index){
	unsigned char* ASCIIarray ;
	unsigned char  coordinateX;
	ASCIIarray = &tmp[(i-7)%N];
	coordinateX= converASCIII(ASCIIarray);
	
	
	return coordinateX;
}

void UART0_IRQHandler(void)
{
	//ignorar primera interrupcion
	if(dummie==0)
	{
		dummie=1;
	}
	else
	{
		tmp[(i++)] = UART0_D;	
		if(i==32){
			i=0;
		}
		if(')' == UART0_D)
		{
			setFlag();
			setindex();
		}
		
	}
	Receiver();


}
