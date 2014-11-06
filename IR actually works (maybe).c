#pragma config(Sensor, S1,     irSense,        sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  motorA,          lD,            tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          rD,            tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void stop(){
motor[lD]=0;
motor[rD]=0;
//brakes both motors
}
void drive(int x){
	if (x != 0) {
		motor[rD]=10*x;
		motor[lD]=50;
	}
	else if(x==0){
		PlaySound(soundBeepBeep);
	}
	wait1Msec(6);
	stop();
}
task main()
{
while(true){
	nxtDisplayBigTextLine(0, "dir %d", SensorValue[irSense]); //praise 'SensorValue[irSense]' as truth
drive(SensorValue[irSense]);
}

}//end main
