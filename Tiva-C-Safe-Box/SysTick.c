/*******************************************************************************************
*
*	@File					SysTick.C
*
*	@Description	Contains the Timer Initialization Function,
*								A Delay Function that Takes delay time in ms.
*				
*	@Note					Delay Function Assumes Clock Frequency of 16MHz.
*
*******************************************************************************************/

#include "SysTick.h"


/**************** SysTick Timer Initialization ****************/
void SysTick_Init(void) {
	
    NVIC_ST_CTRL_R = 0;                 // Disable SysTick during Setup
    NVIC_ST_RELOAD_R = 0x00FFFFFF;      // Maximum Reload Value
    NVIC_ST_CURRENT_R = 0;              // Clear Current Register
    NVIC_ST_CTRL_R = 0x5;               // Enable SysTick with Internal Clock
}


/**************** Delay Function that takes Amount of Clock Cycles to Wait ****************/
void SysTick_wait(uint32_t clock_cycles_to_wait) {
	
	  NVIC_ST_RELOAD_R = clock_cycles_to_wait - 1;      // Set Reload Value
    NVIC_ST_CURRENT_R = 0;             								// Clear Current Register		
    while ((NVIC_ST_CTRL_R & 0x00010000) == 0) {}			// Wait for Count Flag
}


/**************** Delay Function that takes Time in Milliseconds ****************/
void SysTick_delay_ms(uint32_t delay) {
	
	uint32_t i;
	for (i = 0; i < delay; i++) {
		SysTick_wait(16000);
	}
}
