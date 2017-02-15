#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu(Game& game, sf::Font &font) :
	m_game(&game)
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

	std::string play = "PLAY";
	std::string option = "OPTIONS";
	std::string exit = "EXIT";
	
	m_buttons[0] = Button(&m_buttonTexture, &play, &sf::Vector2f(450, 200), &font);
	m_buttons[1] = Button(&m_buttonTexture, &option, &sf::Vector2f(450, 300), &font);
	m_buttons[2] = Button(&m_buttonTexture, &exit, &sf::Vector2f(450, 400), &font);

	m_backgroundSprite.setTexture(m_backgroundTexture);

	m_backgroundSprite.setOrigin(450, 300);
	m_backgroundSprite.setPosition(450, 300);
	m_backgroundSprite.setScale(0.094f, 0.094f);
	m_backgroundSprite.setRotation(122.0f);

}

MainMenu::~MainMenu() 
{

}

void MainMenu::update(GamePadState m_state, sf::Time deltaTime, Xbox360Controller2 m_controller)
{
	if (m_transitionStop)
	{
		checkButtonSelected(m_state, m_controller);
		selectedButton(m_state, m_controller);
	}

	if (m_state.Back && !m_state.Back)
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
	}
	else
	{
		m_transitionStop = true;
	}

	if (m_transitionToOptions)
	{
		if ((m_buttons[0].m_sprite.getPosition().x + m_buttons[0].m_sprite.getLocalBounds().width) > 0)
		{
			for (int i = 0; i < 3; i++)
			{
				m_buttons[i].moveLeft();
			}
			
		}
		else
		{
			m_transitionToOptions = false;
			m_transitionFromOptions = true;
			m_game->m_screen = MenuState::OptionScreen;
		}
	}

	if (m_transitionFromOptions)
	{
		if (m_buttons[0].m_sprite.getPosition().x < 410)
		{
			for (int i = 0; i < 3; i++)
			{
				m_buttons[i].moveRight();
			}
		}
		else
		{
			m_transitionFromOptions = false;
		}
	}


}

void MainMenu::render(sf::RenderWindow & window)
{
	window.clear(sf::Color(220, 20, 60));	//Clears window
	window.draw(m_backgroundSprite);		//Draws the background to the screen
	if (m_transitionStop)
	{
		for (int i = 0; i < 3; i++)
		{
			m_buttons[i].render(window);
		}
	}
	window.display();	//Displays the screen
}

void MainMenu::checkButtonSelected(GamePadState m_state, Xbox360Controller2 m_controller)
{
	switch (m_buttonSelected)
	{
		
	case button::Play:
		m_buttons[0].getFocus();
		m_buttons[1].loseFocus();
		m_buttons[2].loseFocus();
		
		if ((m_state.dpadDown && !m_controller.m_previousState.dpadDown) || (m_state.LeftThumbStick.y > 50 && m_controller.m_previousState.LeftThumbStick.y < 50))
		{
			m_buttonSelected = button::Options;
		}
		
		if ((m_state.dpadUp && !m_controller.m_previousState.dpadUp) || (m_state.LeftThumbStick.y < -50 && m_controller.m_previousState.LeftThumbStick.y > -50))
		{
			m_buttonSelected = button::Exit;
		}
		break;
	case button::Options:
		m_buttons[0].loseFocus();
		m_buttons[1].getFocus();
		m_buttons[2].loseFocus();
	
		if ((m_state.dpadDown && !m_controller.m_previousState.dpadDown) || (m_state.LeftThumbStick.y > 50 && m_controller.m_previousState.LeftThumbStick.y < 50))
		{
			m_buttonSelected = button::Exit;
		}
		
		if ((m_state.dpadUp && !m_controller.m_previousState.dpadUp) || (m_state.LeftThumbStick.y < -50 && m_controller.m_previousState.LeftThumbStick.y > -50))
		{
			m_buttonSelected = button::Play;
		}
		break;
	case button::Exit:
		m_buttons[0].loseFocus();
		m_buttons[1].loseFocus();
		m_buttons[2].getFocus();
		
		if ((m_state.dpadDown && !m_controller.m_previousState.dpadDown) || (m_state.LeftThumbStick.y > 50 && m_controller.m_previousState.LeftThumbStick.y < 50))
		{
			m_buttonSelected = button::Play;
		}

		if ((m_state.dpadUp && !m_controller.m_previousState.dpadUp) || (m_state.LeftThumbStick.y < -50 && m_controller.m_previousState.LeftThumbStick.y > -50))
		{
			m_buttonSelected = button::Options;
		}
		break;
	default:
		break;
	}
}

void MainMenu::selectedButton(GamePadState m_state, Xbox360Controller2 m_controller)
{
	switch (m_buttonSelected)
	{
	case Play:
		if (m_state.A && !m_controller.m_previousState.A)
		{
			m_game->m_screen = MenuState::GameScreen;
		}
		break;
	case Options:
		if (m_state.A && !m_controller.m_previousState.A && !m_transitionFromOptions)
		{
			m_transitionToOptions = true;
		}
		break;
	case Exit:
		if (m_state.A && !m_controller.m_previousState.A)
		{
			exit(0);
		}
		break;
	default:
		break;
	}

}