
/*******************************************************************************
 *
 * 	[File Name]		lcd.h
 *
 * 	[Description]	Header File for LCD Driver.
 *
 *	[Author]		Michael Magdy
 *
 ******************************************************************************/

#ifndef LCD_H_
#define LCD_H_


#include <stdlib.h>
#include "std_types.h"
#include "common_macros.h"
#include "controller_config.h"


/*******************************************************************************
 *                      	LCD Static Configuration				           *
 *******************************************************************************/
/* Control Pins Configuration */
#define LCD_RS_PIN 						PD0
#define LCD_RW_PIN 						PD1
#define LCD_E_PIN 						PD2
#define LCD_CONTROL_PORT				PORTD
#define LCD_CONTROL_PORT_DIRECTION		DDRD

/* Data Port Configuration */
#define LCD_DATA_PORT	 				PORTC
#define LCD_DATA_PORT_DIRECTION			DDRC

/* LCD Commands */
#define LCD_COMMAND_MODE_8BIT_2LINE 	0x38
#define LCD_COMMAND_MODE_4BIT_2LINE 	0x28

#define LCD_COMMAND_CLEAR				0x01
#define LCD_COMMAND_CURSOR_OFF			0x0C
#define LCD_SET_CURSOR					0x80


/*******************************************************************************
 *                      	Functions Prototypes                               *
 *******************************************************************************/
/* Initializes the LCD module */
void LCD_init				(void);

/* Clears the LCD display as well as its memory contents */
void LCD_clear				(void);

/* Sends the given command to the LCD */
void LCD_send_command		(uint8 command);

/* Displays the given char, string, or integer */
void LCD_display_char		(uint8 ch);
void LCD_display_string		(uint8 *str_ptr);
void LCD_display_integer	(sint32 num);

/* Sends the cursor to the given row and column */
void LCD_goto_row_col		(uint8 row, uint8 col);


#endif /* LCD_H_ */
