/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */
#include "TIMER.h"
#include "UART.h"
#include "LPTMR.h"



int main(void)
{	
	//secuencia a seguir
	unsigned char secuencia[8]={0x0000000E,0x0000000C,0x0000000D,0x00000009,0x0000000B,0x00000003,0x00000007,0x00000006};
	unsigned char i=0;
	
	//inicializar módulos
	motorinit();
	Global_UART0_init();
	UART0_init();
	LPTMR_Init();
	TPM_Init();
	
	
	//Interripciones globales hab
	NVIC_ICPR = (1<<12) + (1<<28) + (1<<15) + (1<<17); //boraamos manderass pendientes
	NVIC_ISER = (1<<12) + (1<<28) + (1<<15) + (1<<17); //(Hab interrupciones LPTMR y ADC0)
	
	Receiver();
	
	do{
		
			if(LPTMR_getFlag()==1)
			{
				LPTMR_set_CMR(1000);
				GPIO_Write(secuencia[(i++)%8]);
				LPTMR_setFlag();
			}
		
	}
	while(1);
	return 0;
}

