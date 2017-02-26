
#ifndef Xbox360Controller 
#define Xbox360Controller

#include <SFML\Graphics.hpp>
#include <vector>

// Struct for all the gamepad buttons
struct GamePadState
{
	/// <summary>
	/// All the buttons, sticks and triggers on the gamepad
	/// represented by a bool that represents whether each button is pressed or not.
	/// </summary>
	
	bool A;
	bool B;
	bool X;
	bool Y;
	bool LB;
	bool RB;
	bool leftThumbStickClick;
	bool rightThumbStickClick;
	bool dpadUp;		
	bool dpadDown;
	bool dpadLeft;
	bool dpadRight;
	bool Start;
	bool Back;
	bool Xbox;
	bool RTrigger;
	bool LTrigger;
	
	// Vector for the thumbsticks
	sf::Vector2f RightThumbStick;	
	sf::Vector2f LeftThumbStick;

	float triggers;	// Axis value for the triggers
	float dPadX;	// X Axis value for the d pad
	float dPadY;	// Y Axis value for the d pad
	
};

//Controller class
class Xbox360Controller2
{
public:
	Xbox360Controller2();
	~Xbox360Controller2();
	
	int sf_Joystick_index;			// Index count for multiple controllers if connected
	GamePadState m_currentState;	// The current state of all the buttons
	GamePadState m_previousState;	// The previous state to use to check for the moment a button is pressed
	GamePadState update();
	bool isConnected();

private:
	const int dpadThreshold = 50;	// deadzone for the dpad (really a joystick)
	int m_buttons = 0;
};

#endif // !Xbox360Controller 