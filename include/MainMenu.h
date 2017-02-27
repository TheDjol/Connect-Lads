#ifndef MAIN_MENU
#define MAIN_MENU

#include "Game.h"
#include "Xbox360Controller.h"
#include "Widget.h"
#include <iostream>

// Circular referencing
class Game;
class Button;
class Widget;

enum button	// Enum for the buttons
{
	Play,
	Options,
	Exit
};

class MainMenu
{
public:
	MainMenu(Game& game, sf::Font &font);	// Constructor
	~MainMenu();	// De-Constructor

	void update(GamePadState m_state, sf::Time deltaTime, Xbox360Controller2 m_controller);	// Function to update the main menu
	void render(sf::RenderWindow& window);	// Function to render the main menu
	void checkButtonSelected(GamePadState m_state, Xbox360Controller2 m_controller);	// Function to check which button is selected
	void selectedButton(GamePadState m_state, Xbox360Controller2 m_controller);	// Function to check if the selected button is clicked

private:
	const sf::Vector2f WINDOW_DIMENSIONS = sf::Vector2f(900, 600);	// The dimensions of the screen

	Game *m_game; // The game object
	bool m_timeStop = false;	// Bool to reset the clock
	sf::Time m_time;	// The time object
	const sf::Time TIME_PER_UPDATE = sf::microseconds(1500);	// Constant for updating the time
	button m_buttonSelected = button::Play;	// The button enum which starts on the play button
	sf::Texture m_backgroundTexture;	// The background texture
	sf::Sprite m_backgroundSprite;	// The background sprite

	bool m_transitionStop = false;	// The bool for whether or not the transition has stopped
	bool m_transitionToOptions;	// Whether or not the menu is transitioning to the options screen
	bool m_transitionFromOptions; // Whether or not the menu is transitioning from the options screen

	Button m_buttons[3];	// An array of button objects

	// Shared component of all menu buttons.
	sf::Texture m_buttonTexture;

};
#endif // !MAIN_MENU