/*******************************************************************************
 *
 * Interface:
 * 		(PC0: PC3) -> Connected respectively to (A: D)     of a 74LS47 Decoder.
 * 		(PA0: PA5) -> Connected respectively to (EN1: EN6) of a 74LS47 Decoder.
 *
 ******************************************************************************/

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <avr/io.h>

void display_init		();
void display_send_num	(unsigned char num);
void display_enable		(unsigned char display);

#endif /* DISPLAY_H_ */
