
#include "FSM.h"

void safe_lockout(void) {
	
	char i;
	for(i = '9'; i >='0'; i--) {
		LCD_command(CLEAR_DISPLAY);
		LCD_command(CURSOR_START_1ST_LINE);
		LCD_printString("Lockdown...");
		LCD_command(CURSOR_START_2ND_LINE);
		LCD_data(i);
		delay_s(2);
	}
}

void wait_enter_key(void) {
	char key;
	while(1) {
		key = keypad_getkey();
		if(key == '*') {
			return;
		}
	}
}


void get_password(char *pw_str) {
	
	int i, ch;
	for(i = 0; i < PASSWORD_SIZE; i++) {

		// Get char from keypad and store it in pw_str
		ch = keypad_getkey();
		
		if (ch == '*' || ch == '#') {
			i--;
			continue;
		}

		pw_str[i] = ch;

		// Display char on lcd and shift cursor
		LCD_data(ch);
		LCD_command(SHIFT_CURSOR_RIGHT);

		// Delay
		delay_ms(500);
		
	}
}


void config_state(char *pw_str, State *state_ptr) {
	
	int i, flag0000 = 1;
	
	// Solenoid

	
	// LED
	LED_ON(yellow);	
	
	// LCD
	LCD_welcome();
	
	while(flag0000) {
	
		// Prompt User for New Password
		LCD_welcome_prompt();

		
		// Keypad
		// Get New Password
		get_password(pw_str);
		
		// Wait for Enter key
		wait_enter_key();
		
		// 0000 Check
		for(i = 0; i < PASSWORD_SIZE; i++) {	
			
			if(pw_str[i] != '0') {
				flag0000 = 0;
			}
		}
		
		if(flag0000) {
			LCD_command(CLEAR_DISPLAY);
			LCD_command(CURSOR_START_1ST_LINE);
			LCD_printString("Weak PW: 0000");
			LCD_command(CURSOR_START_2ND_LINE);
			LCD_printString("Enter Another PW");
			delay_s(2);
		}
		
	}
	
	// Wait for Close Safe key
	LCD_command(CLEAR_DISPLAY);
	LCD_command(CURSOR_START_1ST_LINE);
	LCD_printString("PW Entered...");
	LCD_command(CURSOR_START_2ND_LINE);
	LCD_printString("To Lock Safe: #");
	while(keypad_getkey() != '#') {
		*state_ptr = locked;
	}
}


void locked_state(char *password, State *state_ptr) {
	
	char pw_str[4];
	int i, lockout_counter = 0, correct_pw = 0;
	
	// Solenoid

	
	// LEDs
	LED_ON(red);	

	delay_ms(500);
	while(!correct_pw) {	
		
		// Lockout Protocol
		if(lockout_counter >= 3) {
			safe_lockout();
		}
				
		// LCD
		// Prompt User for Password
		LCD_prompt();
				
		// Keypad
		// Get New Password
		get_password(pw_str);
		
		// Wait for Enter key
		wait_enter_key();
	
		// Check Password
		correct_pw = 1;
		for(i = 0; i < PASSWORD_SIZE; i++) {
			if(pw_str[i] != password[i]) {
				correct_pw = 0;
			}
		}
		
		// Correct Password
		if(correct_pw) {
			*state_ptr = unlocked;
			return;
		}
		
		// Incorrect Password
		else {
			lockout_counter++;
			LCD_command(CLEAR_DISPLAY);
			LCD_invalid_password();
		}
	}		
}


void unlocked_state(State *state_ptr) {

	int hold_counter = 0;
	// Solenoid
	
	// LED
	LED_ON(green);
	
	// LCD
	LCD_command(CLEAR_DISPLAY);
	LCD_unlocked_prompt();
	
	// Hold #
	while(keypad_getkey() == '*') {
		if(hold_counter >= 5) {
			*state_ptr = config;
			return;
		}
		
		else {
			hold_counter++;
			delay_s(1);
		}			
	}
	
	// Wait for # key 
	while (keypad_getkey() != '#') {}
		
	*state_ptr = locked;
	return;	
}
