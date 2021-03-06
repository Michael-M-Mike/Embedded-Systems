
/*******************************************************************************
 *
 * 	[File Name]		timer.h
 *
 * 	[Description]	Header File for Timer Driver.
 *
 *	[Author]		Michael Magdy
 *
 ******************************************************************************/

#ifndef TIMER_H_
#define TIMER_H_


#include "std_types.h"
#include "common_macros.h"
#include "controller_config.h"

typedef enum {
	TIMER_NO_CLOCK, TIMER_P_1, TIMER_P_8, TIMER_P_64, TIMER_P_256, TIMER_P_1024,
	TIMER_EXTERNAL_FALLING, TIMER_EXTERNAL_RISING
} TIMER_PRESCALER;


/*******************************************************************************
 *                      	Functions Prototypes                               *
 *******************************************************************************/
void TIMER_0_PWM_init			(TIMER_PRESCALER prescaler);
void TIMER_0_PWM_set_duty_cyle	(uint8 duty_cycle);


#endif /* TIMER_H_ */
