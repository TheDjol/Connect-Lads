#pragma once

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Game.h"
#include "Xbox360Controller.h"
#include "MainMenu.h"
#include "Widget.h"
#include <time.h>

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
	
	//Function to highlight the selected button
	void buttonChosen(int buttonNumber);

	//Adds the appropriate coloured block to the grid.
	void addToColumn(int buttonNumber);

	//Checks if the most reason block placed has an adjacent block of the same colour
	void checkArray(int row,int column, sf::Color colour);

	//Checks if there is a 4 in a row
	void checkLine(int row, int column, int direction1, sf::Color colour);


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
	const int SIZE_OF_BUTTON_ARRAY = 7;
	Button m_buttons[7];
	// Makes a Rectangle shape 2D array that has 6 rows and 7 columns
	const int GAME_GRID_COLUMNS = 7;
	const int GAME_GRID_ROWS = 6;
	sf::RectangleShape m_gameGrid[6][7];

	sf::Color m_gameGridColour[6][7];	// 2-D array to hold the colour of each rectangle shape

	bool m_player = true;	// Bool to determine which player is playing

	int m_buttonNumber = 0; // Int for which button is chosen

	bool m_victory = false;	// Bool for whether or not someone won

	sf::Font m_font;	// The font
	sf::Text m_winner;	// The text	to display who wins
	sf::Text m_return;	// The text to tell the player how to get back to the menu

	sf::Texture m_headTexture[4];	// An array of textures for each head
	sf::Sprite m_headSprite[6][7];	// A 2-D array to hold the head sprites

	sf::Texture m_blankTexture;	// A blank texture to wipe the board

	int m_randomHead = 0; //int for which head should be drawn
};
#endif // !GAMEPLAY_H
