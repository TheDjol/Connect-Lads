#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>
#include "Xbox360Controller.h"
#include "StartScreen.h"
#include <sstream>

enum MenuState
{
	start,
	menuScreen, 
	optionScreen,
	game
};

class startScreen;

//The game class
class Game
{
public:
	Game();		//Game constructor
	~Game();	//Game deconstructor
	void run();	//Function to run the game
	void setGameState(MenuState gameState);	//Function to set the game state
	MenuState m_screen;

private:
	sf::RenderWindow m_window;	//The game window
	void update(sf::Time delta);	//Function to update the game
	void draw(sf::RenderWindow &window);	//The function to draw everything
	GamePadState m_state;	//The current gamepad state
	Xbox360Controller2 m_xController;	//The controller object
	startScreen *m_startScreen;
	sf::Font m_font;
};





#endif