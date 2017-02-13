#pragma once

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Game.h"
#include "Xbox360Controller.h"
#include "MainMenu.h"
#include "Widget.h"

class Game; //Declares game for circular reference

enum Buttons
{
	ButtonA,	//Left most button when looking at the game screen
	ButtonB,
	ButtonC,
	ButtonD,
	ButtonE,
	ButtonF,
	ButtonG		//Right most button when looking at the game screen.
};

class Gameplay
{
public:
	// Constructor
	Gameplay(Game& game, sf::Font &font);
	// De-Constructor
	~Gameplay();

	// Updates the Gameplay screen.
	void update(GamePadState m_state, sf::Time deltaTime, Xbox360Controller2 m_controller);
	// Renders the Gameplay screen.
	void render(sf::RenderWindow& window);

	//Function to edit the text based on if theyre selected
	//And to check if the player is moving between buttons
	void checkButtonSelected(GamePadState m_state, Xbox360Controller2 m_controller);
	//Function to check if buttons are selected 
	void selectedButton(GamePadState m_state, Xbox360Controller2 m_controller);
private:
	Game *m_game; //The game object so you can change game states

	Buttons m_buttonSelected;

	//Bool for whether or not the options screen is transitioning to the menu
	bool m_transitionToMenu;
	//Bool for whether or not the options screen is transitioning in from the menu
	bool m_transitionFromMenu = true;

	sf::Texture m_backgroundTexture;	//Background texture
	sf::Sprite m_backgroundSprite;	//Background sprite

	sf::Texture m_buttonTex;	//Texture for the button

	// Initalizes the number of buttons that will be used to cap off the top of the columns
	Button m_buttons[7];
	// Makes a Rectangle shape 2D array that has 6 rows and 7 columns
	sf::RectangleShape m_gameGrid[6][7];
};
#endif // !GAMEPLAY_H