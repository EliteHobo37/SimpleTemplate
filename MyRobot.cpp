#include "WPILib.h"
#include "Definitions.h"

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 
class RobotDemo : public SimpleRobot
{
	int driveOption;
	
	RobotDrive robotDrive; // robot drive system
	Joystick rStick; // right joystick
	Joystick lStick; // left joystick
	Joystick gStick; // gamepad controller
	Joystick driveStationInput; // driver station buttons and dials
	
	
public:
	RobotDemo():
		robotDrive(LEFT_DRIVE_TALON, RIGHT_DRIVE_TALON),	
		rStick(RIGHT_JOYSTICK_INPUT_CHANNEL), 
		lStick(LEFT_JOYSTICK_INPUT_CHANNEL),
		gStick(GAMEPAD_INPUT_CHANNEL),
		driveStationInput(DRIVE_STATION_INPUT_CHANNEL)
		{
		robotDrive.SetExpiration(0.1);
	}

	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous()
	{
		robotDrive.SetSafetyEnabled(false);
		robotDrive.Drive(-0.5, 0.0); 	// drive forwards half speed
		Wait(2.0); 				//    for 2 seconds
		robotDrive.Drive(0.0, 0.0); 	// stop robot
	}

	/**
	 * Runs the motors with arcade steering. 
	 */
	void OperatorControl()
	{
		robotDrive.SetSafetyEnabled(true);
		while (IsOperatorControl())
		{
			DriveControl(0, ARCADE_2);
			Wait(0.005);
		}
	}
	
	
	void DriveControl(Joystick *inputStick = 0, int override = 0)
	{
		
		if( ! inputStick)
		{
			inputStick = &driveStationInput; 
		}
		
		driveOption = static_cast<int> (inputStick->GetRawAxis(DIAL)) + static_cast<int> (inputStick->GetRawAxis(SWITCH) * (DIAL_MAX_VALUE + 1));
		
		if (override != 0)
		{
		driveOption = override;
		}
		
		switch(driveOption)
		{
		case ARCADE_1:
			robotDrive.ArcadeDrive(-rStick.GetRawAxis(Y_AXIS), -rStick.GetRawAxis(X_AXIS));
			break;

		case ARCADE_2:
			robotDrive.ArcadeDrive(-lStick.GetRawAxis(Y_AXIS), -rStick.GetRawAxis(X_AXIS));
			break;

		case ARCADE_GAMEPAD_1:
			robotDrive.ArcadeDrive(-gStick.GetRawAxis(GAMEPAD_LEFT_STICK_Y), -gStick.GetRawAxis(GAMEPAD_LEFT_STICK_X));
			break;				
		case ARCADE_GAMEPAD_2:
			robotDrive.ArcadeDrive(-gStick.GetRawAxis(GAMEPAD_LEFT_STICK_Y), -gStick.GetRawAxis(GAMEPAD_RIGHT_STICK_X));
			break;

		case TANK_GAMEPAD:
			robotDrive.TankDrive(-gStick.GetRawAxis(GAMEPAD_LEFT_STICK_Y), -gStick.GetRawAxis(GAMEPAD_RIGHT_STICK_Y));
			break;

		case TANK_2:
			robotDrive.TankDrive(-lStick.GetRawAxis(Y_AXIS), -rStick.GetRawAxis(Y_AXIS));
			break;

		//default :
		//	robotDrive.ArcadeDrive(rStick.GetRawAxis(Y_AXIS), rStick.GetRawAxis(X_AXIS));
		//	break;
			
		}
	}
	
	
	
	/**
	 * Runs during test mode
	 */
	
	void Test() 
	{

	}
};

START_ROBOT_CLASS(RobotDemo);

