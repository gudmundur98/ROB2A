#pragma config(Sensor, dgtl7,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop)

const float WHEELBASE = 3.33;//3.99
const int BASELENGTH = 22;



void TurnRight (int deg)
{
	while (abs(SensorValue[rightEncoder]) < deg * WHEELBASE)
	{
		if(vexRT[Btn7D] == 1)//if button 7 D is pressed the motor stops
		{
			motor(rightMotor) = 0;
			motor(leftMotor) = 0;
		}
		else
			{
			motor[leftMotor] = -127;
			motor[rightMotor] = 127;
			}
	}
}

void TurnLeft (int deg)
{
	while (abs(SensorValue[leftEncoder]) < deg * WHEELBASE)
	{
		if(vexRT[Btn7D] == 1)//if button 7 D is pressed the motor stops
		{
			motor(rightMotor) = 0;
			motor(leftMotor) = 0;
		}
		else
		{
			motor[leftMotor] = 127;
			motor[rightMotor] = -127;
		}
	}
}
void drive (int dist)
{
	while(abs(SensorValue[rightEncoder]) < (dist/BASELENGTH)*360) {
		if(vexRT[Btn7D] == 1)//if button 7 D is pressed the motor stops
		{
			motor(rightMotor) = 0;
			motor(leftMotor) = 0;
		}
		else
		{
			motor(rightMotor) = 127;
			motor(leftMotor) = 127;
		}
	}
}


void ResetEncoder()
{
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;


}
