
#include "timer.h"

void timer_1_CTC_init() {

	/***************************************************************************************
	 *
	 * Initializes Timer 1 in CTC Mode to request an interrupt every 1 second.
	 *
	 * 		  F(CPU) = 1 MHz
	 * 			   N = 64
	 *
	 * 		F(Timer) = F(CPU) / N =
	 * 				 = 15.625 kHz
	 *
	 * 		T(Timer) = 1 / F(Timer) =
	 * 				 = 64us
	 *
	 * 		64us * 15625 ticks = 1 second
	 *
	 **************************************************************************************/

	TCCR1A = (1 << FOC1A) | (1 << FOC1B);					// Mode: 4 (CTC with TOP: OCR1A)
	TCCR1B = (1 << WGM12) | (1 << CS10) | (1 << CS11);		// Clock Source: Pre-scaler N = 64
	TCNT1 = 0;												// Initialize counter at 0
	OCR1A = 15625;											// Compare Value = 15625 (1 second)

	TIMSK |= (1 << OCIE1A);									// Enable Output Compare A Match Interrupt
	SREG |= (1 << 7);										// Enable I-bit (Global Interrupt)
}


void stop_timer() {
	TCCR1B &= ~(1 << CS10) & ~(1 << CS11);					// No clock source (Timer stopped)
}

void restart_timer() {
	TCCR1B |= (1 << CS10) | (1 << CS11);					// Clock Source: Pre-scaler N = 64
}
