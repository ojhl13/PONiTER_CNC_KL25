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

unsigned char tmp[N]; //arreglo en donde almacenamos caracteres entrantes
unsigned char i=0; //variable para manejar posicion actual del arreglo State de captura de datos
unsigned char ON=0;
unsigned char cesar =0;
unsigned char done[6] = {'D', 'O', 'N', 'E', '\r' ,'\r'};
//"Overtemperature detected"
unsigned char overtmp[26] = {'O','v','e','r','t','e','m','p','e','r','a','t','u','r','e',' ','d','e','t','e','c','t','e','d','\r','\r'};

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
	UART0_BDL=137;
	UART0_C2=(3<<2); //Enable Transmit and Recieve

}

void Receiver(void)
{
	UART0_C2=0x2C;
}

unsigned char MOTOR_ON(void)
{
	//if(tmp[(i-2)%N]==0x4E && tmp[(i-3)%N] == 0x4F && tmp[(i-4)%N] == 0x3A && tmp[(i-5)%N] == 0x52 && tmp[(i-6)%N] == 0x4F && tmp[(i-7)%N] == 0x54 && tmp[(i-8)%N] == 0x4F && tmp[(i-9)%N] == 0x4D)
	if(tmp[(i-2)%N]=='N' && tmp[(i-3)%N] == 'O' && tmp[(i-4)%N] == ':' && tmp[(i-5)%N] == 'R' && tmp[(i-6)%N] == 'O' && tmp[(i-7)%N] == 'T' && tmp[(i-8)%N] == 'O' && tmp[(i-9)%N] == 'M')
	{
		return 1;
	}
	return 0;
}

unsigned char MOTOR_OFF(void)
{
	//if(tmp[(i-2)%N]==0x46 && tmp[(i-3)%N] == 0x46 && tmp[(i-4)%N] == 0x4F && tmp[(i-5)%N] == 0x3A && tmp[(i-6)%N] == 0x52 && tmp[(i-7)%N] == 0x4F && tmp[(i-8)%N] == 0x54 && tmp[(i-9)%N] == 0x4F && tmp[(i-10)%N] == 0x4D)
	if(tmp[(i-2)%N]=='F' && tmp[(i-3)%N] == 'F' && tmp[(i-4)%N] == 'O' && tmp[(i-5)%N] == ':' && tmp[(i-6)%N] == 'R' && tmp[(i-7)%N] == 'O' && tmp[(i-8)%N] == 'T' && tmp[(i-9)%N] == 'O' && tmp[(i-10)%N] == 'M')	
	{
		//GPIOD_PTOR=1<<1;
		return 1;
	}
	return 0;
}

unsigned char DIR_CW(void)
{
	//if(tmp[(i-2)%N]==0x57 && tmp[(i-3)%N]==0x43 && tmp[(i-4)%N]==0x3A && tmp[(i-5)%N]==0x52 && tmp[(i-6)%N]==0x49 && tmp[(i-7)%N]==0x44)
	if(tmp[(i-2)%N]=='W' && tmp[(i-3)%N]=='C' && tmp[(i-4)%N]== ':' && tmp[(i-5)%N]=='R' && tmp[(i-6)%N]=='I' && tmp[(i-7)%N]=='D')
	
		{
			return 1;
		}
	return 0;
}

unsigned char DIR_CCW(void)
{
	//if(tmp[(i-2)%N]==0x57 && tmp[(i-3)%N]==0x43 && tmp[(i-4)%N]==0x43 && tmp[(i-5)%N]==0x3A && tmp[(i-6)%N]==0x52 && tmp[(i-7)%N]==0x49 && tmp[(i-8)%N]==0x44)
	if(tmp[(i-2)%N]== 'W' && tmp[(i-3)%N]== 'C' && tmp[(i-4)%N]== 'C' && tmp[(i-5)%N]== ':' && tmp[(i-6)%N]== 'R' && tmp[(i-7)%N]== 'I' && tmp[(i-8)%N]== 'D')
		{
			return 1;
		}
	return 0;
}

unsigned char STEPCW(void)
{
	//no se que es este codigo
	//if(tmp[(i-5)%N]==0x3A && tmp[(i-6)%N]==0x57 && tmp[(i-7)%N]==0x43 && tmp[(i-8)%N]==0x50 && tmp[(i-9)%N]==0x45 && tmp[(i-10)%N]==0x54 &&  tmp[(i-11)%N]==0x53)
	if(tmp[(i-5)%N]==':' && tmp[(i-6)%N]=='W' && tmp[(i-7)%N]=='C' && tmp[(i-8)%N]=='P' && tmp[(i-9)%N]=='E' && tmp[(i-10)%N]=='T' &&  tmp[(i-11)%N]=='S')
		{
			//if((0x30 <= tmp[(i-4)%N] <= 0x33) && (0x30 <= tmp[(i-3)%N] <= 0x39) && (0x30 <= tmp[(i-2)%N] <= 0x39))
			if((tmp[(i-4)%N] >= '0' && tmp[(i-4)%N] <= '9') && (tmp[(i-3)%N] >= '0' && tmp[(i-3)%N] <= '9') && (tmp[(i-2)%N] >= '0' && tmp[(i-2)%N] <= '9'))
			{
				return 1;
			}
		}
	return 0;
}

unsigned char RPS(void)
{
	if(tmp[(i-6)%N]==':' && tmp[(i-7)%N]=='S' && tmp[(i-8)%N]=='P' && tmp[(i-9)%N]=='R')
		{
			if((tmp[(i-5)%N] >= '0' && tmp[(i-5)%N] <= '9') && (tmp[(i-4)%N] >= '0' && tmp[(i-4)%N] <= '9') && tmp[(i-3)%N] == '.' && (tmp[(i-2)%N] >= '0' && tmp[(i-2)%N] <= '9'))
			{
				return 1;
			}
		}
	return 0;
}

//TEMPLIMIT:ttt.t
unsigned char TEMPLIMIT(void)
{
	if(tmp[(i-7)%N]==':' && tmp[(i-8)%N]=='T' && tmp[(i-9)%N]=='I' && tmp[(i-10)%N]=='M' &&  tmp[(i-11)%N]=='I' && tmp[(i-12)%N]=='L' && tmp[(i-13)%N]=='P' && tmp[(i-14)%N]=='M' && tmp[(i-15)%N]=='E' && tmp[(i-16)%N]=='T')
			{
				if((tmp[(i-6)%N] >= '0' && tmp[(i-6)%N] <= '9') &&(tmp[(i-5)%N] >= '0' && tmp[(i-5)%N] <= '9') &&(tmp[(i-4)%N] >= '0' && tmp[(i-4)%N] <= '9') && tmp[(i-3)%N] == '.' && (tmp[(i-2)%N] >= '0' && tmp[(i-2)%N] <= '9'))
				{
					return 1;
				}
			}
		return 0;
}


void DoneMessage(void)
{
	unsigned char i=0;
	do{
	do{}while(!(UART0_S1&(1<<7)));
	UART0_D=done[i++];
	}while(done[i]!=0);
}

void OverTmp(void)
{
	unsigned char i=0;
	do{
	do{}while(!(UART0_S1&(1<<7)));
	UART0_D=overtmp[i++];
	}while(overtmp[i]!=0);
}

unsigned char getOn(void)
{
	return ON;
}

void UART0_IRQHandler(void)
{
	//ignorar primera interrupcion
	if(cesar==0)
	{
		cesar=1;
	}
	else
	{
		tmp[(i++)%N] = UART0_D;
		if(tmp[(i-1)%N]==0x0D)
		{
			if(MOTOR_ON())
			{
				//PONER 1 EN POSICION 1 DE VARIABLE ESTADO 
				ON=1;
				GPIOD_PTOR=1<<1;
				DoneMessage();
			}
			else if(MOTOR_OFF())
			{
				ON=0;
				GPIOD_PTOR=1<<1;
				DoneMessage();
			}
		}
	}
	Receiver();


}
