#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>
#include "Xbox360Controller.h"
#include "StartScreen.h"
#include "MainMenu.h"
#include "Options.h"
#include "Gameplay.h"
#include <sstream>
#include <SFML/Audio.hpp>

enum MenuState
{
	Start,
	MenuScreen, 
	OptionScreen,
	GameScreen
};

class Gameplay;
class startScreen;
class MainMenu;
class OptionsScreen;

//The game class
class Game
{
public:
	Game();		//Game constructor
	~Game();	//Game deconstructor
	void run();	//Function to run the game
	void setGameState(MenuState gameState);	//Function to set the game state
	MenuState m_screen;

	void pauseMusic(bool pauseMusic);

private:
	sf::RenderWindow m_window;	//The game window
	void update(sf::Time delta);	//Function to update the game
	void draw(sf::RenderWindow &window);	//The function to draw everything
	GamePadState m_state;	//The current gamepad state
	Xbox360Controller2 m_xController;	//The controller object
	Xbox360Controller2 m_prevController;	//The controller object
	startScreen *m_startScreen;
	MainMenu *m_mainMenu;
	OptionsScreen *m_options;
	Gameplay *m_gamePlay;
	sf::Font m_font;
	sf::Music m_music;
};

#endif !GAME_H