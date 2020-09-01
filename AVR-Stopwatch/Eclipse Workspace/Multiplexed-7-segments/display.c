/*******************************************************************************
 *
 * Interface:
 * 		(PC0: PC3) -> Connected respectively to (A: D)     of a 74LS47 Decoder.
 * 		(PA0: PA5) -> Connected respectively to (EN1: EN6) of a 74LS47 Decoder.
 *
 ******************************************************************************/

#include "display.h"

void display_init() {

	DDRA |= 0x3F;		// PA0: PA5 -> Output
	PORTA &= ~(0x3F);	// PA0: PA5 = 0 (Disable all displays)

	DDRC |= 0x0F;		// PC0: PC3 -> Output
	PORTC &= ~(0x0F);	// PC0: PC3 = 0 (Display zeros)
}

void display_send_num(unsigned char num) {

	/***************************************************
	 *
	 * Inputs:
	 * 		num: number to be sent to the decoder lines.
	 *
	 * 	Outputs:
	 * 		The given number is sent to be displayed.
	 *
	 *  Assumption:
	 *  	 0 <= num <= 9
	 *
	 **************************************************/

	PORTC &= 0xF0;		// Clear current num
	PORTC |= num;		// Set current num
}

void display_enable(unsigned char display_num) {

	/***************************************************************
	 *
	 * Inputs:
	 * 		display_num: number of the display to be enabled
	 *
	 * 	Outputs:
	 * 		Enables the wanted display.
	 * 		Disables all other displays.
	 *
	 * 	Assumptions:
	 * 		0 <= display_num <= NUM_DISPLAYS
	 *
	 **************************************************************/

	PORTA &= ~(0x3F);				// Disable all displays
	PORTA |= (1 << display_num);	// Enable wanted display

}
