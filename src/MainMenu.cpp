#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu(Game& game, sf::Font &font) :
	m_game(&game),
	m_playText("PLAY", font, 32),
	m_optionsText("OPTIONS", font, 32),
	m_exitText("EXIT", font, 32)
{
	if (!m_backgroundTexture.loadFromFile(".\\resources\\images\\startBG.jpg"))
	{
		{
			std::string s("Error loading texture");	//Outputs error message
			throw std::exception(s.c_str());
		}
	}

	m_backgroundSprite.setTexture(m_backgroundTexture);

	m_backgroundSprite.setOrigin(450, 300);
	m_backgroundSprite.setPosition(450, 300);
	m_backgroundSprite.setScale(0.094f, 0.094f);
	m_backgroundSprite.setRotation(122.0f);
}

MainMenu::~MainMenu() 
{

}

void MainMenu::update(GamePadState m_state, sf::Time deltaTime)
{
	static int count = 0;
	if (m_state.Back)
	{
		exit(0);
	}

	if (!m_timeStop)
	{
		deltaTime.Zero;
		m_timeStop = true;
	}
	
	if (m_time.asSeconds() <= 3.6)
	{
		m_backgroundSprite.setRotation(m_backgroundSprite.getRotation() - 2);	//Rotates the sprite
		m_backgroundSprite.scale(1.001, 1.001);	//Scales up the sprite
		m_time += TIME_PER_UPDATE;	//Increments the counter
		count++;
		
	}
	else
	{
		std::cout << count << std::endl;
	}
}

void MainMenu::render(sf::RenderWindow & window)
{
	window.clear(sf::Color(220, 20, 60));	//Clears window
	window.draw(m_backgroundSprite);		//Draws text to the screen
	window.display();	//Displays the screen
}