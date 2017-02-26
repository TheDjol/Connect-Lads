#include "Xbox360Controller.h"
#include <iostream>

// Constructor for the controller
Xbox360Controller2::Xbox360Controller2()
{

};

// Deconstructor for the controller
Xbox360Controller2::~Xbox360Controller2()
{

};

// Function to update the controller
GamePadState Xbox360Controller2::update()
{
	sf::Joystick::update();	// Updates the joystick
	if (isConnected())	// Checks if the controller is connected
	{
		m_buttons = sf::Joystick::getButtonCount(0); // Gets the button count
		sf::Joystick::Identification id = sf::Joystick::getIdentification(0);	// Gets the id of the joystick
		m_previousState = m_currentState;	// Sets the current state to be the previous state
		

		/// <summary>
		/// These if statements check if a button is pressed
		/// And set it to be pressed if it is,
		/// If they're not pressed
		/// Sets them to not be pressed
		/// </summary>
		
		if (sf::Joystick::isButtonPressed(0, 0))
		{
			m_currentState.A = true;
		}
		else
		{
			m_currentState.A = false;
		}

		if (sf::Joystick::isButtonPressed(0, 1))		
		{												
			m_currentState.B = true;					
		}												
		else
		{
			m_currentState.B = false;
		}

		if (sf::Joystick::isButtonPressed(0, 2))
		{
			m_currentState.X = true;
		}
		else
		{
			m_currentState.X = false;
		}

		if (sf::Joystick::isButtonPressed(0, 3))
		{
			m_currentState.Y = true;
		}
		else
		{
			m_currentState.Y = false;
		}

		if (sf::Joystick::isButtonPressed(0, 4))
		{
			m_currentState.LB = true;
		}
		else
		{
			m_currentState.LB = false;
		}

		if (sf::Joystick::isButtonPressed(0, 5))
		{
			m_currentState.RB = true;
		}
		else
		{
			m_currentState.RB = false;
		}

		if (sf::Joystick::isButtonPressed(0, 6))
		{
			m_currentState.Back = true;
		}
		else
		{
			m_currentState.Back = false;
		}

		if (sf::Joystick::isButtonPressed(0, 7))
		{
			m_currentState.Start = true;
		}
		else
		{
			m_currentState.Start = false;
		}

		if (sf::Joystick::isButtonPressed(0, 8))
		{
			m_currentState.leftThumbStickClick = true;
		}
		else
		{
			m_currentState.leftThumbStickClick = false;
		}

		if (sf::Joystick::isButtonPressed(0, 9))
		{
			m_currentState.rightThumbStickClick = true;
		}
		else
		{
			m_currentState.rightThumbStickClick = false;
		}

		/// <summary>
		/// Checks the Triggers.
		/// </summary>

		m_currentState.triggers = sf::Joystick::getAxisPosition(0, sf::Joystick::Z);

		if (m_currentState.triggers > 50)	// Checks if the left trigger is pressed
		{
			m_currentState.LTrigger = true;
		}
		else
		{
			m_currentState.LTrigger = false;
		}

		if (m_currentState.triggers < -0.1)	//Checks if the right trigger is pressed
		{
			m_currentState.RTrigger = true;
		}
		else
		{
			m_currentState.RTrigger = false;
		}

		/// <summary>
		/// Checks the Dpads axis'
		/// </summary>

		m_currentState.dPadX = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX);	//Gets the d pads x axis

		m_currentState.dPadY = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY);	//Gets the d pads y axis


		if (m_currentState.dPadX < -0.1)	//Checks if the left d pad button is pressed
		{
			m_currentState.dpadLeft = true;
		}
		else
		{
			m_currentState.dpadLeft = false;
		}

		if (m_currentState.dPadX > 50)		//Checks if the right d pad button is pressed
		{
			m_currentState.dpadRight = true;
		}
		else
		{
			m_currentState.dpadRight = false;
		}

		if (m_currentState.dPadY < -0.1)	//Checks if the down d pad button is pressed
		{ 
			m_currentState.dpadDown = true;
		}
		else
		{
			m_currentState.dpadDown = false;
		}

		if (m_currentState.dPadY > 50)		//Checks if the up d pad button is pressed
		{
			m_currentState.dpadUp = true;
		}
		else
		{
			m_currentState.dpadUp = false;
		}

		/// <summary>
		/// Gets the joysticks positions
		/// </summary>

		m_currentState.RightThumbStick.x = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::U);
		m_currentState.RightThumbStick.y = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::R);
		m_currentState.LeftThumbStick.x = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X);
		m_currentState.LeftThumbStick.y = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y);
	}

	return m_currentState;	//returns the gamepad state
};

//Functions to check whether or not the controller is connected
bool Xbox360Controller2::isConnected()
{
	if (sf::Joystick::isConnected(0))	//Checks if the controller is connected
	{
		return true;	//Returns true if it is
	}
	else 
	{
		return false;	//returns false if it isnt
	}
}