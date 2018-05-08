/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */
#include "motor.h"
#include "UART.h"




int main(void)
{	

	
	//inicializar módulos
	motorinit();
	Global_UART0_init();
	UART0_init();


	
	
	//Interripciones globales hab
	NVIC_ICPR = (1<<12) + (1<<28) + (1<<15) + (1<<17); //boraamos manderass pendientes
	NVIC_ISER = (1<<12) + (1<<28) + (1<<15) + (1<<17); //(Hab interrupciones LPTMR y ADC0)
	
	Receiver();
	
	do{
		
			
		
	}
	while(1);
	return 0;
}

