/**********************************************************************
*  
*	@File					keypad.h
*
*	@Description 	Header file for keypad.c
*
***********************************************************************/  

#include <stdint.h>
#include "tm4c123gh6pm.h"

void keypad_Init       (void);
char keypad_getkey     (void);
