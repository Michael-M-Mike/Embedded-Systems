
/*******************************************************************************
 *
 * 	[File Name]		motor_driver.h
 *
 * 	[Description]	Header File for Motor Driver.
 *
 *	[Author]		Michael Magdy
 *
 ******************************************************************************/

#ifndef MOTOR_DRIVER_H_
#define MOTOR_DRIVER_H_


#include "std_types.h"
#include "common_macros.h"
#include "controller_config.h"


/*******************************************************************************
 *                          External Variables                                 *
 *******************************************************************************/
/* Extern Public global variables to be used by other modules */
extern volatile uint16 g_MOTOR_direction;


/*******************************************************************************
 *                          Static Configuration							   *
 *******************************************************************************/
// #define MOTOR_EN1			PA0
#define MOTOR_IN1 				PB1
#define MOTOR_IN2 				PB2
/*
#define MOTOR_EN2
#define MOTOR_IN3
#define MOTOR_IN4
*/
#define MOTOR_PORT 				PORTB
#define MOTOR_PORT_DIRECTION	DDRB



/*******************************************************************************
 *                          Dynamic Configuration							   *
 *******************************************************************************/
typedef enum {
	CLOCKWISE, COUNTER_CLOCKWISE
} ROTATION;


typedef struct {
	ROTATION rotation;
} MOTOR_TYPE_CONFIG;


/*******************************************************************************
 *                      	Functions Prototypes                               *
 *******************************************************************************/
/* Initializes the motors' driver module */
void MOTOR_1_init	(void);
void MOTOR_2_init	(void);

/* Motor Control */
void MOTOR_1_ON		(MOTOR_TYPE_CONFIG* motor_rotation);
void MOTOR_1_OFF	(void);
void MOTOR_2_ON		(MOTOR_TYPE_CONFIG* motor_rotation);
void MOTOR_2_OFF	(void);


#endif /* MOTOR_DRIVER_H_ */
