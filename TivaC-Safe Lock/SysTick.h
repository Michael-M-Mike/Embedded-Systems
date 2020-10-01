/**********************************************************************************
*
*	@File					SysTick.h
*
*	@Description	Header File for SysTick.c
*				
*	@Note					Delay Function Assumes Clock Frequency of 16MHz.
*
**********************************************************************************/

#include <stdint.h>
#include "tm4c123gh6pm.h"

void SysTick_Init			(void);
void SysTick_wait			(uint32_t clock_cycles_to_wait);
void SysTick_delay_ms	(uint32_t delay);
