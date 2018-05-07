/*
 * motor.c
 *
 *  Created on: May 7, 2018
 *      Author: oscar
 */
#include "motor.h"
#include "GPIO.h"

#define LEFT 1
#define RIGTH 0
#define UP	1
#define DOWN 0 
#define MOTORX 1
#define MOTORY 0



static unsigned char actualpositionX;
static unsigned char actualpositionY;
static unsigned char secuencia[8]={0x0000000E,0x0000000C,0x0000000D,0x00000009,0x0000000B,0x00000003,0x00000007,0x00000006};

void motorinit(void)
{
	Global_GPIO_init();
	actualpositionX=0;
	actualpositionY=0;
}
void start(void)
{
	
	u_int8 steps;/* variable que indicara cuantos pasos se requiere mover para llegar la inicio*/
	steps=0;
	
	steps = diference(actualpositionX,0);
	steps = convertMM2Steps(steps);
	moveMotor(steps,LEFT,MOTORX);//mover en X
	
	
	steps = diference(actualpositionY,0);
	steps = convertMM2Steps(steps);
	moveMotor(steps,UP,MOTORY);//mover en X
		
	
	
	
}

unsigned char diference(unsigned char ActualPos, unsigned char NewPos )
{
	unsigned char data2ret;
	data2ret =0;
	if( ActualPos < NewPos)
	{
		data2ret = NewPos - ActualPos;
	}
	else
	{
		data2ret = ActualPos - NewPos;
	}
		
	return data2ret;
}

void moveMotor( unsigned char steps  )
{
	unsigned char i;
	i=0;
	while( steps--){
	GPIO_Write(secuencia[(i++)%8]);
	}

}



