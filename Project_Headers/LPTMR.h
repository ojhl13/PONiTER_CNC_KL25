/*
 * LPTMR.h
 *
 *  Created on: Apr 3, 2018
 *      Author: Fernando
 */

#ifndef LPTMR_H_
#define LPTMR_H_

/*Initialize Low Power Timer*/
void LPTMR_Init(void);

void LPTMR_IRQHandler(void);

unsigned char LPTMR_getFlag(void);

void LPTMR_set_CMR(unsigned long);

void LPTMR_setFlag(void);

#endif /* LPTMR_H_ */
