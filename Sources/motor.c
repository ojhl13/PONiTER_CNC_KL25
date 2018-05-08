/*
 * motor.c
 *
 *  Created on: May 7, 2018
 *      Author: oscar
 */
#include "motor.h"
#include "GPIO.h"
#include "types.h"


#define LEFT 1
#define RIGTH 0
#define UP	1
#define DOWN 0 
#define MOTORX 1
#define MOTORY 0
#define MMSTEPRELATION 5 // steps necesarios para avanzar un milimetro

unsigned char GetDirection(unsigned char ActualPos, unsigned char NewPos );
unsigned char diference(unsigned char ActualPos, unsigned char NewPos );
void moveMotor( unsigned char steps ,unsigned char direction, unsigned char motor );
unsigned char convertMM2Steps(unsigned char mm);

static unsigned char actualpositionX;
static unsigned char actualpositionY;
static unsigned char secuencia[8]={0x0000000E,0x0000000C,0x0000000D,0x00000009,0x0000000B,0x00000003,0x00000007,0x00000006};
static unsigned char i;
static unsigned char j;
void motorinit(void)
{
	i=0;
	j=0;
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
	moveMotor(steps,UP,MOTORY);//mover en Y
		
	
	
	
}
unsigned char convertMM2Steps(unsigned char mm)
{
	return (mm/MMSTEPRELATION);
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

void moveMotor( unsigned char steps ,unsigned char direction, unsigned char motor )
{
	
	while( steps--){
		if(motor == MOTORX)
		{
			if(direction == LEFT)
			{
				GPIO_Write_PB(secuencia[(i++)%8]);
			}
			else
			{
				GPIO_Write_PB(secuencia[(i--)%8]);
			}
		}
		else
		{
			if(direction == UP)
			{
				GPIO_Write_PC(secuencia[(i++)%8]);
			}
			else
			{
				GPIO_Write_PC(secuencia[(i--)%8]);
			}
		}
	
	}

}
unsigned char GetDirection(unsigned char ActualPos, unsigned char NewPos )
{
	unsigned char direction;
	direction =0;
	if( ActualPos < NewPos)
	{
		
	}
}
void GoToNewPos(unsigned char coorX, unsigned char coorY )
{
	u_int8 steps;/* variable que indicara cuantos pasos se requiere mover para llegar la inicio*/
	u_int8 dir;
	steps=0;
	dir=0;
	steps = diference(actualpositionY,coorY);
	steps = convertMM2Steps(steps);
	dir= GetDirection(actualpositionY,coorY);
	moveMotor(steps,dir,MOTORY);//mover en Y
		
	steps = diference(actualpositionX,coorX);
	steps = convertMM2Steps(steps);
	dir= GetDirection(actualpositionX,coorX);
	moveMotor(steps,dir,MOTORX);//mover en X
		
		
	
			
}

