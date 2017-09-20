#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)


/*----------------------------------------------------------------------------------------------------*\
|*                                     - Suicide Verkefni 2 -                                         *|
|*                                    ROBOTC on VEX 2.0 CORTEX                                        *|
|*                                                                                                    *|
|*  This program instructs your robot to move forward at full power for half a meter forward then     *|
|*  half a meter backwards and always adds half a meter until the robot has done 2.5 meters           *|
|*                                                                                                    *|
|*                                                                             												*|
|*                                                                                                    *|
|       																																															*|
\*----------------------------------------------------------------------------------------------------*/

task main()
{
	const int TIMER = 1180;
	for(int i = 1; i < 6; i++)
	{
		motor[rightMotor] = 127;
		motor[leftMotor]  = 127;
		wait1Msec(TIMER*i);

		motor[rightMotor] = -127;
		motor[leftMotor]  = -127;
		wait1Msec(TIMER*i);

	}
}
