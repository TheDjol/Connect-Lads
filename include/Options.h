#pragma once

#ifndef OPTIONS
#define	OPTIONS

#include "Game.h"
#include "Xbox360Controller.h"
#include "MainMenu.h"

class Game; //Declares game for circular reference

enum optionButton	//An enum for which button is selected
{
	//All the option buttons
	Option1,
	Option2,
	Option3
};

//The option screen class
class OptionsScreen
{
public:
	OptionsScreen(Game& game, sf::Font &font);	//Constructor
	~OptionsScreen();	//De-constructor
	//Function to update the options creen
	void update(GamePadState m_state, sf::Time deltaTime, Xbox360Controller2 m_controller);
	//function to render the options screen
	void render(sf::RenderWindow& window);
	//Function to edit the text based on if theyre selected
	//And to check if the player is moving between buttons
	void checkButtonSelected(GamePadState m_state, Xbox360Controller2 m_controller);
	//Function to check if buttons are selected 
	void selectedButton(GamePadState m_state, Xbox360Controller2 m_controller);

private:
	Game *m_game; //The game object so you can change game states
	optionButton m_oButton = optionButton::Option1;	//The enum starts at option 1
	//Bool for whether or not the options screen is transitioning to the menu
	bool m_transitionToMenu;	
	//Bool for whether or not the options screen is transitioning in from the menu
	bool m_transitionFromMenu = true;

	sf::Texture m_backgroundTexture;	//Background texture
	sf::Sprite m_backgroundSprite;	//Background sprite

	sf::Texture m_buttonTex;	//Texture for the button

	//The two button sprites
	sf::Sprite m_button1;
	sf::Sprite m_button2;

	sf::RectangleShape m_slider;	//The slider

	//The two pieces of text
	sf::Text m_button1Text;
	sf::Text m_button2text;
};

#endif // !OPTIONS
