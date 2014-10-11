#ifndef _CATAPULT_H
#define _CATAPULT_H

#include "WPILib.h"
#include "Definitions.h"

class Catapult
{
	
	public:
	Catapult(unsigned int motorChannel, unsigned int encoderChannel1, unsigned int encoderChannel2);
	void MoveTo(float position, float speedMultiplyer = .2);
	void Stop();
	
	private:
	Catapult();
	void GoUp(float velocity);
	void GoDown(float velocity);
	
	
	Jaguar  motor;
	Encoder encoder;
};








#endif
