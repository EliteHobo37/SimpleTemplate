#include "Catapult.h"

Catapult::Catapult()
		:motor(0),
		 encoder(1, 2)
{
	//Should NOT be used.
}
Catapult::Catapult(unsigned int motorChannel, unsigned int encoderChannel1, unsigned int encoderChannel2)
		:motor(motorChannel),
		 encoder(encoderChannel1, encoderChannel2)
{
	motor.StopMotor();
	encoder.Start();
	encoder.Reset();
}

void Catapult::MoveTo(float position, float speedMultiplyer)
{
	float velocity;
	velocity = speedMultiplyer * MAX_MOTOR_SPEED;
	
	if (encoder.GetDistance() > position)
	{
		GoDown(velocity);
	}
	if (encoder.GetDistance() < position)	
	{
		GoUp(velocity);
	}
	else
	{
		motor.Set(0);
	}
	
}

void Catapult::Stop()
{

}





void Catapult::GoUp(float velocity)
{
	motor.Set(velocity);
}

void Catapult::GoDown(float velocity)
{
	motor.Set(-velocity);
}
