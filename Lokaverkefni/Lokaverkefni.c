#pragma config(Sensor, in5,    lineFollowerRIGHT, sensorLineFollower)
#pragma config(Sensor, in6,    lineFollowerLEFT, sensorLineFollower)
#pragma config(Sensor, in7,    lineFollowerCENTER, sensorLineFollower)
#pragma config(Sensor, in1,    lightSensor,    sensorReflection)
#pragma config(Sensor, dgtl11, sonarSensor,    sensorSONAR_cm)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           clawMotor,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port4,           armMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Sensor, dgtl7,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  leftEncoder,    sensorQuadEncoder)

/*----------------------------------------------------------------------------------------------------*\
|*                                     -  Lokaverkefni  -                                    	 			  *|
|*                                    ROBOTC on VEX 2.0 CORTEX                                        *|
|* 	In this program the user can run all the previous program that he has created with a press of a	  *|
|*          						button. Each project is binded to a specific button.													*|
|*                                                                                                    *|
|*          Notes: U 87,9cm   					Thermal = 7 * pi = 22		encoder = 360 = U											*|
|*          const int =87,9 /21,99 = 3,99 *90 = 359,1                                                 *|
|       																																															*|
\*----------------------------------------------------------------------------------------------------*/

#include "../myfunction/drivefunctions.c"


task suicide(){//verkefni-2 1.hluti
	const int TIMER = 1180;
	for(int i = 1; i < 3; i++)
	{
		motor[rightMotor] = 127;
		motor[leftMotor]	= 127;
		wait1Msec(TIMER*i);

		motor[rightMotor] = -127;
		motor[leftMotor]	= -127;
		wait1Msec(TIMER*i);

	}
		StopAllTasks();
}


task mase(){//verkefni-3 2.hluti

			ResetEncoder();
			drive(50);

			ResetEncoder();
			TurnLeft(90);

			ResetEncoder();
			drive(50);

			ResetEncoder();
			TurnRight(90);

			ResetEncoder();
			drive(50);

			ResetEncoder();
			TurnRight(90);

			ResetEncoder();
			drive(50);

			StopAllTasks();

}

task controller(){//verkefni 3 1.hluti
	while(1 == 1)
	{
			motor[leftMotor] = vexRT[Ch3] / 2;		//left joystick
			motor[rightMotor] = vexRT[Ch2] / 2;		//right joystick

			if(vexRT[Btn6D] == 1)//if button 6 D is pressed arm goes down
			{
				motor[armMotor] = 40;
			}

			else if(vexRT[Btn6U] == 1)//if button 6 U is pressed arm goes up
			{
				motor[armMotor] = -40;
			}
			else //else the motor stops
			{
       motor[armMotor] = 0;
			}

			if(vexRT[Btn8L]==1)//if button 8 L is pressed the claw opens
			{
				motor[clawMotor] = 40;
			}

			else if(vexRT[Btn8R] == 1)//if button 8 R is pressed the claw closes
			{
				motor[clawMotor] = -40;
			}
			else //this stops the claw motor
			{
       motor[clawMotor] = 0;
			}
			if(vexRT[Btn7D] == 1)//if button 7D is preesed robot stops
			{
				StopAllTasks();
			}
	}
}

task driveWithSensors()//verkefni 4
{
	wait1Msec(2000);
	while(true) // While the ambient lightSensor reads a value less than 300
	{

		if(SensorValue(sonarSensor) > 30  || SensorValue(sonarSensor) == -1)//the robot will drive when the sonar cant sense a object within 30 cm
		{
			motor[rightMotor] = 127;
			motor[leftMotor]  = 127;
		}
		else{
		ResetEncoder();
		TurnLeft(90);
		}
		if(vexRT[Btn7D] == 1)
			{
				StopAllTasks();
			}
	}
}

task driveWithLineSensor() //verkefni 5
{
  int threshold = 250;

  while(true)
  {

    displayLCDCenteredString(0, "LEFT  CNTR  RGHT");
    displayLCDPos(1,0);
    displayNextLCDNumber(SensorValue(lineFollowerLEFT));
    displayLCDPos(1,6);
    displayNextLCDNumber(SensorValue(lineFollowerCENTER));
    displayLCDPos(1,12);
    displayNextLCDNumber(SensorValue(lineFollowerRIGHT));

		if(vexRT[Btn7D] == 1)
			{
				StopAllTasks();
			}

    if(SensorValue(lineFollowerRIGHT) > threshold)
    {
     	if(vexRT[Btn7D] == 1)//if button 7 D is pressed the motor stops
			{
				motor(rightMotor) = 0;
				motor(leftMotor) = 0;
			}

			else{
     		motor[leftMotor]  = 0;
      	motor[rightMotor] = 63;
    	}
    }

    if(SensorValue(lineFollowerCENTER) > threshold)
    {
      if(vexRT[Btn7D] == 1)//if button 7 D is pressed the motor stops
			{
				motor(rightMotor) = 0;
				motor(leftMotor) = 0;
			}
			else{
      	motor[leftMotor]  = 63;
      	motor[rightMotor] = 63;
    	}
    }

    if(SensorValue(lineFollowerLEFT) > threshold)
    {
      if(vexRT[Btn7D] == 1)//if button 7 D is pressed the motor stops
		{
			motor(rightMotor) = 0;
			motor(leftMotor) = 0;
		}

		else{
      motor[leftMotor]  = 63;
      motor[rightMotor] = 0;
    	}
    }
  }
}


task GetBall()//verkefni 6
{
	int threshold = 250;

  while(true)
  {

  	if(vexRT[Btn7D] == 1)
			{
				StopAllTasks();
			}

    displayLCDCenteredString(0, "LEFT  CNTR  RGHT");
    displayLCDPos(1,0);
    displayNextLCDNumber(SensorValue(lineFollowerLEFT));
    displayLCDPos(1,6);
    displayNextLCDNumber(SensorValue(lineFollowerCENTER));
    displayLCDPos(1,12);
    displayNextLCDNumber(SensorValue(lineFollowerRIGHT));



    if(SensorValue(lineFollowerRIGHT) > threshold)
    {
     	if(vexRT[Btn7D] == 1)//if button 7 D is pressed the motor stops
			{
				motor(rightMotor) = 0;
				motor(leftMotor) = 0;
			}
			else{
      	motor[leftMotor]  = 0;
      	motor[rightMotor] = 63;
    	}
    }

    if(SensorValue(lineFollowerCENTER) > threshold)
    {
      if(vexRT[Btn7D] == 1)//if button 7 D is pressed the motor stops
			{
				motor(rightMotor) = 0;
				motor(leftMotor) = 0;
			}

			else{
     	 motor[leftMotor]  = 63;
      	motor[rightMotor] = 63;
    	}
    }

    if(SensorValue(lineFollowerLEFT) > threshold)
    {
      if(vexRT[Btn7D] == 1)//if button 7 D is pressed the motor stops
		{
			motor(rightMotor) = 0;
			motor(leftMotor) = 0;
		}
		else{
      motor[leftMotor]  = 63;
      motor[rightMotor] = 0;
    }
    if(SensorValue(sonarSensor) > 10  || SensorValue(sonarSensor) == -1)//the robot will drive when the sonar cant sense a object within 30 cm
		{
					motor[rightMotor] = 0;
					motor[leftMotor]  = 0;
					motor[clawMotor] = -40;//open claw
					wait1Msec(2000);
					motor[clawMotor] = 30;//close claw
					wait1Msec(2000);
					motor[clawMotor] = 0;//claw stop
					wait1Msec(2000);
					motor[rightMotor] = 63;//Turn around
					motor[leftMotor]  = -63;
					wait1Msec(2300);

				}
				if(vexRT[Btn7D] == 1)
				{
				StopAllTasks();
				}
    }
  }
}


task main()
{

	while(true)
	{
			if(vexRT[Btn7L] == 1)
			{
				StartTask(suicide);
			}
			if(vexRT[Btn7U] == 1)
			{
				StartTask(mase);
			}
			if(vexRT[Btn7R] == 1)
			{
				StartTask(controller);
			}

			if(vexRT[Btn7D] == 1)
			{
				StartTask(driveWithSensors);
			}

			if(vexRT[Btn8L] == 1)
			{
				StartTask(driveWithLineSensor);
			}

			if(vexRT[Btn8U] == 1)
			{
				StartTask(GetBall);
			}
	}

}
