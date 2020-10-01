
#include "LEDs.h"
#include "delay.h"
#include "keypad.h"
#include "LCD.h"


#define PASSWORD_SIZE 4

typedef enum State {
	
	locked 		= 0,
	unlocked 	= 1,
	config 		= 2
} State;


void safe_lockout			(void);
void wait_enter_key		(void);
void get_password			(char *pw_str);
void config_state			(char *pw_str, State *state_ptr);
void locked_state			(char *password, State *state_ptr); 
void unlocked_state		(State *state_ptr);
