
/*******************************************************************************
 *
 * 	[File Name]		controller_config.h
 *
 * 	[Description]	File containing the mcu's configuration and libraries.
 *
 *	[Author]		Michael Magdy
 *
 ******************************************************************************/

#ifndef CONTROLLER_CONFIG_H_
#define CONTROLLER_CONFIG_H_


/* Clock Frequency */
#ifndef F_CPU
#define F_CPU 1000000UL
#endif

/* MCU Libraries */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


#endif /* CONTROLLER_CONFIG_H_ */
