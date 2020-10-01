# Safe-Box
A Tiva C-Based Safe Project Implemented in C.

# Overview
The Tiva C microcontroller is interfaced with:
      
* Keypad
* LCD
* Solenoid Lock
* Buzzer

The safe-box allows the user to configure a specific 4-digit password, then the safe can be locked. It can be unlocked at any time by entering the configured password. A reset feature allows the user to re-configure the safe password, provided they can unlock the safe.

# Finite State Machine
The project is implemented as the following finite state machine,

![FSM Image](https://github.com/Michael-M-Mike/Tiva-C-Safe-Box/blob/master/state%20machine.png)
