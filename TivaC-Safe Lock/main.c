#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "LEDs.h"
#include "delay.h"
#include "keypad.h"
#include "LCD.h"
#include "FSM.h"

void SystemInit() {};

	
// Global Variables
State state = config;
char PASSWORD[4];

int main(void) {

	LEDs_init();
	keypad_Init();
	LCD_Init();
	
	while(1) {
		
		switch(state) {
			
			case config:
				config_state(PASSWORD, &state);
				break;
			
			case locked:
				locked_state(PASSWORD, &state);
				break;
			
			case unlocked:
				unlocked_state(&state);
				break;
		}
	}
	
}
