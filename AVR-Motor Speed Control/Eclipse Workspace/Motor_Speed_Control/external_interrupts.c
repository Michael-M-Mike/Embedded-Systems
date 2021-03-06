
/*******************************************************************************
 *
 * 	[File Name]		external_interrupts.c
 *
 * 	[Description]	Source File for External Interrupts Driver.
 *
 *	[Author]		Michael Magdy
 *
 ******************************************************************************/

#include "external_interrupts.h"


/*******************************************************************************
 *                          Global Variables                                   *
 *******************************************************************************/
/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_INT0_callback_ptr)(void) = NULL_PTR;
static volatile void (*g_INT1_callback_ptr)(void) = NULL_PTR;


/*******************************************************************************
 *                           ISR Definitions                                   *
 *******************************************************************************/
ISR(INT0_vect) {

	/* Run the callback function if set by the user */
	if (g_INT0_callback_ptr != NULL_PTR) {
		g_INT0_callback_ptr();
	}
}

ISR(INT1_vect) {

	/* Run the callback function if set by the user */
	if (g_INT1_callback_ptr != NULL_PTR) {
		g_INT1_callback_ptr();
	}
}


/*******************************************************************************
 *                            EXT_INT Functions                                *
 *******************************************************************************/
void INT0_init(const EXT_INT_TYPE_CONFIG * config_ptr) {

	/* Enable external interrupt INT0 */
	GICR  |= (1 << INT0);

	/* Configure INT0 Sense Control */
	MCUCR |= config_ptr->sense_control;

	/* Set PD2 (INT0) as input */
	DDRD &= ~ (1 << PD2);
}

void INT1_init(const EXT_INT_TYPE_CONFIG * config_ptr) {

	/* Enable external interrupt INT1 */
	GICR  |= (1 << INT1);

	/* Configure INT0 Sense Control */
	MCUCR |= (config_ptr->sense_control << 2);

	/* Set PD3 (INT1) as input */
	DDRD &= ~ (1 << PD3);
}

void INT0_set_callback(void (*callback_fn_ptr)(void)) {
	g_INT0_callback_ptr = callback_fn_ptr;
}

void INT1_set_callback(void (*callback_fn_ptr)(void)) {
	g_INT1_callback_ptr = callback_fn_ptr;
}
