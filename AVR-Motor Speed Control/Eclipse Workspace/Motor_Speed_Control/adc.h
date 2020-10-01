
/*******************************************************************************
 *
 * 	[File Name]		adc.h
 *
 * 	[Description]	Header File for ADC Driver.
 *
 *	[Author]		Michael Magdy
 *
 ******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
#include "common_macros.h"
#include "controller_config.h"


/*******************************************************************************
 *                          External Variables                                 *
 *******************************************************************************/
/* Extern Public global variables to be used by other modules */
extern volatile uint16 g_ADC_channel;


/*******************************************************************************
 *                          Dynamic Configuration							   *
 *******************************************************************************/
/* Reference Selection (Vref > Vsensor_max) */
typedef enum {
	AREF, AVCC, ADC_VREF_RESERVED, V2_56
} ADC_VREF;


/* ADC Prescaler Select Bits (by which the CPU frequency is divided) */
typedef enum {
	ADC_P_2, ADC_PRESCALER_RESERVED, ADC_P_4, ADC_P_8,
	ADC_P_16, ADC_P_32, ADC_P_64, ADC_P_128
} ADC_PRESCALER;


/* Structure containing the ADC configuration parameters */
typedef struct {
	ADC_VREF vref;
	ADC_PRESCALER prescaler;
} ADC_TYPE_CONFIG;


/*******************************************************************************
 *                      	Functions Prototypes                               *
 *******************************************************************************/
/* Initializes the ADC module */
void ADC_init			(const ADC_TYPE_CONFIG * config_ptr);

/* Starts the ADC conversion,
 * triggers an interrupt when the channel is read.
 * The result is stored in a global variable (g_ADC_channel).
 * Then, the callback function is called (if set).
 */
void ADC_read_channel 	(uint8 channel_num);

/* Sets the callback function to be executed when the interrupt is triggered. */
void ADC_set_callback	(void (*callback_fn_ptr)(void));


#endif /* ADC_H_ */
