
/*******************************************************************************
 *
 * 	[File Name]		lcd.c
 *
 * 	[Description]	Source File for LCD Driver.
 *
 *	[Author]		Michael Magdy
 *
 ******************************************************************************/

#include "lcd.h"


/*******************************************************************************
 *                            LCD Functions                                    *
 *******************************************************************************/
void LCD_init(void) {

	// Set the 8 data pins as output
	LCD_DATA_PORT_DIRECTION = 0xFF;

	// Set the RS, R/W, and E pins as output
	SET_BIT(LCD_CONTROL_PORT_DIRECTION, LCD_RS_PIN);
	SET_BIT(LCD_CONTROL_PORT_DIRECTION, LCD_RW_PIN);
	SET_BIT(LCD_CONTROL_PORT_DIRECTION, LCD_E_PIN);

	// Set LCD Mode: 8 bits transmission, 2 lines display
	LCD_send_command(LCD_COMMAND_MODE_8BIT_2LINE);

	// Clear the display
	LCD_send_command(LCD_COMMAND_CLEAR);

	// Hide the cursor
	LCD_send_command(LCD_COMMAND_CURSOR_OFF);
}


void LCD_clear(void) {
	LCD_send_command(LCD_COMMAND_CLEAR);
}


void LCD_goto_row_col(uint8 row, uint8 col) {

	uint8 address;

	switch (row) {
		case 0:
			address = col;
			break;
		case 1:
			address = col + 0x40;
			break;
		case 2:
			address = col + 0x10;
			break;
		case 3:
			address = col + 0x50;
			break;
	}

	LCD_send_command(LCD_SET_CURSOR | address);
}


void LCD_send_command(uint8 command) {

	// Clear the enable bit
	CLEAR_BIT(LCD_CONTROL_PORT, LCD_E_PIN);

	// Clear the RS bit for command transfer
	CLEAR_BIT(LCD_CONTROL_PORT, LCD_RS_PIN);

	// Clear the R/W bit for write mode
	CLEAR_BIT(LCD_CONTROL_PORT, LCD_RW_PIN);

	// Delay (tas)
	_delay_ms(1);

	// Set the enable bit
	SET_BIT(LCD_CONTROL_PORT, LCD_E_PIN);

	// Delay (tpw - tdsw)
	_delay_ms(1);

	// Send the given command
	LCD_DATA_PORT = command;

	// Delay (tdsw)
	_delay_ms(1);

	// Clear the enable bit
	CLEAR_BIT(LCD_CONTROL_PORT, LCD_E_PIN);

	// Delay (th)
	_delay_ms(1);
}


void LCD_display_char(uint8 ch) {

	// Clear the enable bit
	CLEAR_BIT(LCD_CONTROL_PORT, LCD_E_PIN);

	// Clear the RS bit for data transfer
	SET_BIT(LCD_CONTROL_PORT, LCD_RS_PIN);

	// Clear the R/W bit for write mode
	CLEAR_BIT(LCD_CONTROL_PORT, LCD_RW_PIN);

	// Delay (tas)
	_delay_ms(1);

	// Set the enable bit
	SET_BIT(LCD_CONTROL_PORT, LCD_E_PIN);

	// Delay (tpw - tdsw)
	_delay_ms(1);

	// Send the given character
	LCD_DATA_PORT = ch;

	// Delay (tdsw)
	_delay_ms(1);

	// Clear the enable bit
	CLEAR_BIT(LCD_CONTROL_PORT, LCD_E_PIN);

	// Delay (th)
	_delay_ms(1);

}


void LCD_display_string(uint8 *str_ptr) {

	uint8 i;

	/* Iterate over the chars array */
	for(i = 0; str_ptr[i] != '\0'; i++) {

		/* Display each char */
		LCD_display_char(str_ptr[i]);
	}
}


void LCD_display_integer(sint32 num) {

	char string[16];

	/* Convert integer to an array of chars */
	itoa(num, string, 10);

	/* Display the array */
	LCD_display_string(string);
}
