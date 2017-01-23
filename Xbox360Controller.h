
#ifndef Xbox360Controller 
#define Xbox360Controller

#include <SFML\Graphics.hpp>
#include <vector>

//Struct for all the gamepad buttons
struct GamePadState
{
	bool A;
	bool B;
	bool X;
	bool Y;
	bool LB;
	bool RB;
	bool leftThumbStickClick;
	bool rightThumbStickClick;
	bool dpadUp;		//All the buttons, sticks and triggers on the gamepad
	bool dpadDown;
	bool dpadLeft;
	bool dpadRight;
	bool Start;
	bool Back;
	bool Xbox;
	bool RTrigger;
	bool LTrigger;
	//Vector fo the thumbsticks
	sf::Vector2f RightThumbStick;	
	sf::Vector2f LeftThumbStick;
	float triggers;	//Axis value for the triggers
	float dPadX;	// X Axis value for the d pad
	float dPadY;	//Y Axis value for the d pad
	
};

//Controller class
class Xbox360Controller2
{
public:
	Xbox360Controller2();

	// index count for multiple controllers if connected
	int sf_Joystick_index;
	// the current state of all the buttons
	GamePadState m_currentState;
	// the previous state to use to check for the moment a button is pressed
	GamePadState m_previousState;
	~Xbox360Controller2();
	GamePadState update();
	bool isConnected();

private:
	// deadzone for the dpad (really a joystick)
	const int dpadThreshold = 50;
	int m_buttons = 0;

};

#endif // !Xbox360Controller 




