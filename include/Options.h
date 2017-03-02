#pragma once

#ifndef OPTIONS
#define	OPTIONS

#include "Game.h"
#include "Xbox360Controller.h"
#include "MainMenu.h"
#include "Widget.h"

class Game; // Declares game for circular reference.

enum optionButton	// An enum for which button is selected.
{
	/// <summary>
	/// All the option buttons.
	/// </summary>
	Option1,
	Option2,
	Option3
};

class OptionsScreen
{
public:
	OptionsScreen(Game& game, sf::Font &font, sf::RenderWindow &window);	// Constructor for the options screen.
	~OptionsScreen();	// Destructor function for the options screen.
	
	void update(GamePadState m_state, sf::Time deltaTime, Xbox360Controller2 m_controller);	// Function to update the options screen.
	void render(sf::RenderWindow& window);	// Function to render the options screen.

	/// <summary>
	/// Function to edit the text based on if theyre selecte
	/// And to check if the player is moving between buttons</summary>
	/// <param name="m_state"></param>
	/// <param name="m_controller"></param>
	void checkButtonSelected(GamePadState m_state, Xbox360Controller2 m_controller);
	void selectedButton(GamePadState m_state, Xbox360Controller2 m_controller);	// Function to check if buttons are selected.
	void changeWindowResolution(sf::RenderWindow& window);	// Changes the size of the game window when the slider is moved.

private:
	Game *m_game; // The game object so you can change game states
	optionButton m_oButton = optionButton::Option1;	// The enum starts at option 1
	
	bool m_transitionToMenu;	// Bool for whether or not the options screen is transitioning to the menu
	bool m_transitionFromMenu = true;	// Bool for whether or not the options screen is transitioning in from the menu

	sf::RenderWindow  &m_window;	// Stores the address of the window.
	sf::Font m_font;	// Stores the font used to draw the text.
	sf::Texture m_backgroundTexture;	// Background texture
	sf::Sprite m_backgroundSprite;	// Background sprite

	Button m_buttons;	// Button object on the options screen.
	sf::Texture m_buttonTex;	// Texture for the button.

	Label m_label[2];	// The Labels used to describe the function of other widgets.
	std::string m_labelText[2];	// The String of text assigned to the label.

	Slider m_slider;	// The slider
	int m_sliderValue;	// Stores a copy of what segment the slider is on.

	RadioButton m_radioButton; // The radio button
	bool m_previouslyFilled;	// Checks if the radioButton was filled or emptied since the last update.

	sf::Texture m_emptyRadioButtonTex;	// Texture for the empty radio button
	sf::Texture m_fullRadioButtonTex;	// Texture for the full radio button
};

#endif // !OPTIONS
