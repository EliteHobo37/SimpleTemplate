#ifndef _DEFINITIONS_H
#define _DEFINITIONS_H

//Joystick Definitions
#define LEFT_JOYSTICK_INPUT_CHANNEL 	1
#define RIGHT_JOYSTICK_INPUT_CHANNEL 	2
#define GAMEPAD_INPUT_CHANNEL 			3
#define DRIVE_STATION_INPUT_CHANNEL		4

#define DIAL 							1 //CHECK VALUE!!!!
#define SWITCH 							2 //CHECK VALUE!!!!

#define Y_AXIS 							2 //CHECK VALUE!!!!
#define X_AXIS 							1 //CHECK VALUE!!!!

#define GAMEPAD_LEFT_STICK_Y 			2 //CHECK VALUE!!!!
#define GAMEPAD_LEFT_STICK_X 			1 //CHECK VALUE!!!!
#define GAMEPAD_RIGHT_STICK_Y 			5 //CHECK VALUE!!!!
#define GAMEPAD_RIGHT_STICK_X 			4 //CHECK VALUE!!!!

//Drive Mode Switch & Dial
#define ARCADE_1 			0 
#define ARCADE_2 			ARCADE_1 + 1
#define ARCADE_GAMEPAD_1 	ARCADE_2 + 1
#define ARCADE_GAMEPAD_2 	ARCADE_GAMEPAD_1 + 1

#define TANK_GAMEPAD 		DIAL_MAX_VALUE + 1 
#define TANK_2 				TANK_GAMEPAD + 1

#define SWITCH_ARCADE		0
#define SWITCH_TANK			1
#define DIAL_MAX_VALUE	 	3 //CHECK VALUE!!!!

//Drive Control
#define LEFT_DRIVE_TALON 	1
#define RIGHT_DRIVE_TALON 	2
#define MAX_MOTOR_SPEED		1 // value <= 1







#endif
