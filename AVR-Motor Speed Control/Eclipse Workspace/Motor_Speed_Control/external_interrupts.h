
/*******************************************************************************
 *
 * 	[File Name]		external_interrupts.h
 *
 * 	[Description]	Header File for External Interrupts Driver.
 *
 *	[Author]		Michael Magdy
 *
 ******************************************************************************/

#ifndef EXTERNAL_INTERRUPTS_H_
#define EXTERNAL_INTERRUPTS_H_


#include "std_types.h"
#include "common_macros.h"
#include "controller_config.h"


/*******************************************************************************
 *                          Dynamic Configuration							   *
 *******************************************************************************/
/* Interrupt Sense Control */
typedef enum {
	LOW_LEVEL, LEVEL_CHANGE, FALLING_EDGE, RISING_EDGE
} EXT_INT_SENSE_CTRL;


/* Structure containing the External Interrupt configuration parameters */
typedef struct {
	EXT_INT_SENSE_CTRL sense_control;
} EXT_INT_TYPE_CONFIG;


/*******************************************************************************
 *                      	Functions Prototypes                               *
 *******************************************************************************/
/* Initializes the INT modules */
void INT0_init			(const EXT_INT_TYPE_CONFIG * config_ptr);
void INT1_init			(const EXT_INT_TYPE_CONFIG * config_ptr);

/* Sets the callback functions to be executed when the interrupt is triggered. */
void INT0_set_callback	(void (*callback_fn_ptr)(void));
void INT1_set_callback	(void (*callback_fn_ptr)(void));


#endif /* EXTERNAL_INTERRUPTS_H_ */
