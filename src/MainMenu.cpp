#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu(Game& game, sf::Font &font) :
	m_game(&game),
	m_playText("PLAY", font, 28),
	m_optionsText("OPTIONS", font, 28),
	m_exitText("EXIT", font, 28)
{
	if (!m_backgroundTexture.loadFromFile(".\\resources\\images\\startBG.jpg"))
	{
		{
			std::string s("Error loading texture");	//Outputs error message
			throw std::exception(s.c_str());
		}
	}

	if (!m_buttonTexture.loadFromFile(".\\resources\\images\\Button.png"))
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

	m_playSprite.setTexture(m_buttonTexture);
	m_playSprite.setPosition(370,200);
	m_playText.setPosition(405, 205);

	m_optionsSprite.setTexture(m_buttonTexture);
	m_optionsSprite.setPosition(370, 300);
	m_optionsText.setPosition(375, 305);

	m_exitSprite.setTexture(m_buttonTexture);
	m_exitSprite.setPosition(370, 400);
	m_exitText.setPosition(405, 405);
}

MainMenu::~MainMenu() 
{

}

void MainMenu::update(GamePadState m_state, sf::Time deltaTime, Xbox360Controller2 m_controller)
{
	checkButtonSelected(m_state, m_controller);
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
		m_transitionStop = true;
		std::cout << count << std::endl;
	}
}

void MainMenu::render(sf::RenderWindow & window)
{
	window.clear(sf::Color(220, 20, 60));	//Clears window
	window.draw(m_backgroundSprite);		//Draws text to the screen
	if (m_transitionStop)
	{
		window.draw(m_playSprite);
		window.draw(m_optionsSprite);
		window.draw(m_exitSprite);
		window.draw(m_playText);
		window.draw(m_optionsText);
		window.draw(m_exitText);
	}
	window.display();	//Displays the screen
}

void MainMenu::checkButtonSelected(GamePadState m_state, Xbox360Controller2 m_controller)
{
	

	

	

	switch (m_button)
	{
		
	case button::Play:
		m_playText.setColor(sf::Color(236, 0, 24));
		m_optionsText.setColor(sf::Color(0, 0, 0));
		m_exitText.setColor(sf::Color(0, 0, 0));
		

		if ((m_state.dpadDown && !m_controller.m_previousState.dpadDown) || (m_state.LeftThumbStick.y > 50 && m_controller.m_previousState.LeftThumbStick.y < 50))
		{
			m_button = button::Options;
		}
		
		if ((m_state.dpadUp && !m_controller.m_previousState.dpadUp) || (m_state.LeftThumbStick.y < -50 && m_controller.m_previousState.LeftThumbStick.y > -50))
		{
			m_button = button::Exit;
		}

		break;
	case button::Options:
		m_playText.setColor(sf::Color(0, 0, 0));
		m_optionsText.setColor(sf::Color(236, 0, 24));
		m_exitText.setColor(sf::Color(0, 0, 0));
	
		if ((m_state.dpadDown && !m_controller.m_previousState.dpadDown) || (m_state.LeftThumbStick.y > 50 && m_controller.m_previousState.LeftThumbStick.y < 50))
		{
			m_button = button::Exit;
		}
		if ((m_state.dpadUp && !m_controller.m_previousState.dpadUp) || (m_state.LeftThumbStick.y < -50 && m_controller.m_previousState.LeftThumbStick.y > -50))
		{
			m_button = button::Play;
		}
		break;
	case button::Exit:
		m_playText.setColor(sf::Color(0, 0, 0));
		m_optionsText.setColor(sf::Color(0, 0, 0));
		m_exitText.setColor(sf::Color(236, 0, 24));
		if ((m_state.dpadDown && !m_controller.m_previousState.dpadDown) || (m_state.LeftThumbStick.y > 50 && m_controller.m_previousState.LeftThumbStick.y < 50))
		{
			m_button = button::Play;
		}

		if ((m_state.dpadUp && !m_controller.m_previousState.dpadUp) || (m_state.LeftThumbStick.y < -50 && m_controller.m_previousState.LeftThumbStick.y > -50))
		{
			m_button = button::Options;
		}
		break;
	default:
		break;
		
	}


}