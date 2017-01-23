#include "Game.h"
#include "Xbox360Controller.h"
#include <iostream>

//Game constructor
Game::Game()
	:m_window(sf::VideoMode(900, 600, 32), "Connect Lads", sf::Style::Default),	//Sets up the window
	m_screen(MenuState::start)
{
	
	m_startScreen = new startScreen(*this);
}

//Game deconstructor
Game::~Game()
{

}

//Runs the game, holds the game loop
void Game::run()
{
	static double const MS_PER_UPDATE = 10.0;
	sf::Clock clock;
	sf::Int32 lag = 0;
	
	while (m_window.isOpen())
	{
		sf::Time dt = clock.restart();		//The game loop

		lag += dt.asMilliseconds();

		while (lag > MS_PER_UPDATE)
		{
			update(dt);		//Updates the game every second
			lag -= MS_PER_UPDATE;
		}
		update(dt);		//Updates the game every second
		draw(m_window);		//Draws the game
	}
	
	

}

//Sets the gamestate
void Game::setGameState(MenuState gameState)
{
	m_screen = gameState;	//Sets the current gamestate to be the gamestate passed to the function
}

//Function to update the game
void Game::update(sf::Time delta)
{
	m_state = m_xController.update();	//Updates the controller
	m_startScreen->update(m_state);
}

//Function to draw all visual info to the screen
void Game::draw(sf::RenderWindow &window)
{
	
	window.display();		//Displays the window to the screen
}




