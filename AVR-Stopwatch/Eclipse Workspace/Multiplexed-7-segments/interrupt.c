/*******************************************************************************
 *
 * Interface:
 * 		PD2 (INT0) -> Falling Edge w/ Internal Pull-Up   Resistor.
 * 		PD3 (INT1) -> Rising  Edge w/ External Pull-Down Resistor.
 * 		PB2 (INT2) -> Falling Edge w/ Internal Pull-Up   Resistor.
 *
 ******************************************************************************/

#include "interrupt.h"

void interrupts_init() {

	DDRD &= ~(1 << PD2) & ~(1 << PD3);		// PD2/PD3: Input
	DDRB &= ~(1 << PB2);					// PB2: 	Input

	PORTD |= (1 << PD2);					// PD2: Enable internal pull-up configuration
	PORTB |= (1 << PB2);					// PB2: Enable internal pull-up configuration

	MCUCR |= (1 << ISC01);					// INT0 (PD2): Falling Edge
	MCUCR |= (1 << ISC10) | (1 << ISC11);	// INT1 (PD3): Rising  Edge
	MCUCSR &= ~(1 << ISC2);					// INT2 (PB2): Falling Edge

	GICR |= 0xE0;							// Enable INT0, INT1, INT2
	SREG |= (1 << 7);						// Enable I-bit (Global Interrupts)
}
