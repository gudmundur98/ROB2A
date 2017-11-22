#pragma config(Sensor, in5,    lineFollowerRIGHT, sensorLineFollower)
#pragma config(Sensor, in6,    lineFollowerLEFT, sensorLineFollower)
#pragma config(Sensor, in7,    lineFollowerCENTER, sensorLineFollower)
#pragma config(Sensor, dgtl11, sonarSensor,    sensorSONAR_cm)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           clawMotor,     tmotorServoStandard, openLoop)


task main()
{
  wait1Msec(2000);

  int threshold = 1200;

  while(true)
  {

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
      motor[leftMotor]  = 63;
      motor[rightMotor] = 0;
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
      motor[leftMotor]  = 0;
      motor[rightMotor] = 63;
    }
    if(SensorValue(sonarSensor) = 1  || SensorValue(sonarSensor) == -1)//if robot gets 1 cm close to an object the robot will turn
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
    }
  }
}
