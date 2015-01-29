#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S3, HTServo,  none,     none,     none)
#pragma config(Hubs,  S4, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Sensor, S4,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     rightWheel1,   tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     rightWheel2,   tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C1_1,     leftWheel1,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     leftWheel2,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C1_1,     h,             tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C1_2,     kjg,           tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S3_C1_1,    front,                tServoStandard)
#pragma config(Servo,  srvo_S3_C1_2,    back,                 tServoStandard)
#pragma config(Servo,  srvo_S3_C1_3,    lift1,                tServoStandard)
#pragma config(Servo,  srvo_S3_C1_4,    lift2,                tServoStandard)
#pragma config(Servo,  srvo_S3_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  // allows bluetooth messaging

#define backDown 250
#define backUp 125
#define frontDown 225
#define frontUp 125

//void initializeRobot() {}

task main() {
	//waitForStart();
	//initializeRobot();
	int modifier = 4; // set modifier variable
	while (true) {
		servo[lift1] = servo[lift2] = getJoystickSettings(joystick); // gets joystick input
		modifier = 1;
		if (abs(joystick.joy1_y1) > 10){
			motor[leftWheel1] = (-joystick.joy1_y1 / modifier); // reads joystick values on joystick one.
			motor[leftWheel2] = (-joystick.joy1_y1 / modifier);
		}	else {
			motor[leftWheel1] = 0;
			motor[leftWheel2] = 0;
		}

		if (abs(joystick.joy1_y2) > 10)	{
			motor[rightWheel1] = (-joystick.joy1_y2 / modifier); // the 'y'(up and down) axis values set the power.
			motor[rightWheel2] = (-joystick.joy1_y2 / modifier);
		}	else {
			motor[rightWheel1] = 0;
			motor[rightWheel2] = 0;
		}

		if (joy1Btn(5)) { // change it back to joy2 after testing
			servo[back] = backUp;
		}	else if(joy1Btn(7)) { // change it back to joy2 after testing
			servo[back] = backDown;
		}

		if (joy1Btn(6)) {
			servo[front]=frontUp;
		} else if (joy1Btn(8)) {
			servo[front]=frontDown;
		}
	}
}
