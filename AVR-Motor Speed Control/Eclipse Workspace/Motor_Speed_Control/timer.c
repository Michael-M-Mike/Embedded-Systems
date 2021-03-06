
/*******************************************************************************
 *
 * 	[File Name]		timer.c
 *
 * 	[Description]	Source File for Timer Driver.
 *
 *	[Author]		Michael Magdy
 *
 ******************************************************************************/

#include "timer.h"


/*******************************************************************************
 *                            Timer Functions                                  *
 *******************************************************************************/
void TIMER_0_PWM_init(TIMER_PRESCALER prescaler) {

	/* Initialize Timer Count*/
	TCNT0 = 0;

	/* Set Compare Value (Initial Duty Cycle = 50%) */
	OCR0  = 128;

	/* Configure the OC0 PIN as Output */
	DDRB  = DDRB | (1<<PB3);

	/* Configure PWM in Non-inverting Mode */
	TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | prescaler;

	/* Configure the OC0 PIN as Output */
	SET_BIT(DDRD, PD5);
}


void TIMER_0_PWM_set_duty_cyle(uint8 duty_cycle) {

	/* Map 0-100 Range to 0-255 Range */
	/*
	 * y = mx + q
	 *
	 * q = 0
	 *
	 * m = 255 / 100
	 *
	 */

	uint8 y = ((float32)255 / 100) * duty_cycle;
	OCR0  = y;
}
