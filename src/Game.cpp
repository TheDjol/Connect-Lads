#include "Game.h"
#include "Xbox360Controller.h"
#include <iostream>

//Game constructor
Game::Game()
	:m_window(sf::VideoMode(900, 600, 32), "Connect Lads", sf::Style::Default),	//Sets up the window
	m_screen(MenuState::Start)
{
	if (!m_font.loadFromFile(".\\resources\\fonts\\arial.ttf"))	//Checks to make sure font is correct
	{
		std::cout << "Problem loading font file!" << std::endl;
	}
	m_startScreen = new startScreen(*this, m_font);
	m_mainMenu = new MainMenu(*this, m_font);
	m_options = new OptionsScreen(*this, m_font, m_window);
	m_gamePlay = new Gameplay(*this, m_font);

	if (!m_music.openFromFile(".\\resources\\Music\\Chopin_-_Nocturne_op.wav"))
	{
		std::cout << "Problem loading music file!" << std::endl;
	}

	m_music.play();
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

	switch (m_screen)
	{
	case Start:
		m_startScreen->update(m_state, delta);
		//std::cout << "m_screen == start" << std::endl;
		break;
	case MenuScreen:
		m_mainMenu->update(m_state, delta, m_xController);
		//std::cout << "m_screen == menuScreen" << std::endl;
		break;
	case OptionScreen:
		m_options->update(m_state, delta, m_xController);
		break;
	case GameScreen:
		m_gamePlay->update(m_state, delta, m_xController);
		break;
	default:
		break;
	}
	

}

//Function to draw all visual info to the screen
void Game::draw(sf::RenderWindow &window)
{
	//m_window.setSize(sf::Vector2u(400, 400));
	switch (m_screen)
	{
	case MenuState::Start:
		m_startScreen->render(m_window);
		break;
	case MenuState::MenuScreen:
		m_mainMenu->render(m_window);
		break;
	case MenuState::OptionScreen:
		m_options->render(m_window);
		break;
	case MenuState::GameScreen:
		m_gamePlay->render(m_window);
		break;
	default:
		m_window.clear(sf::Color::Blue);	//Clears screen
		m_window.display();	//Displays the screen
		break;
	}
}