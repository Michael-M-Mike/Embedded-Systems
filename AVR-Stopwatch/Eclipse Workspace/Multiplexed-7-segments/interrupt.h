/*******************************************************************************
 *
 * Interface:
 * 		PD2 (INT0) -> Falling Edge w/ Internal Pull-Up   Resistor.
 * 		PD3 (INT1) -> Rising  Edge w/ External Pull-Down Resistor.
 * 		PB2 (INT2) -> Falling Edge w/ Internal Pull-Up   Resistor.
 *
 ******************************************************************************/

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include <avr/interrupt.h>

void interrupts_init	();

#endif /* INTERRUPT_H_ */
