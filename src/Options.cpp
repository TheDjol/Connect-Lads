#include "..\include\Options.h"

OptionsScreen::OptionsScreen(Game& game, sf::Font &font) :
	m_game(&game),
	m_button1Text("YEAH", font, 28),
	m_button2text("WAHU", font, 28),
	m_button3text("BOYO", font, 28)
	
{
	if (!m_backgroundTexture.loadFromFile(".\\resources\\images\\startBG.jpg"))
	{
		{
			std::string s("Error loading texture");	//Outputs error message
			throw std::exception(s.c_str());
		}

	}

	if (!m_buttonTex.loadFromFile(".\\resources\\images\\Button.png"))
	{
		{
			std::string s("Error loading texture");	//Outputs error message
			throw std::exception(s.c_str());
		}
	}

	m_backgroundSprite.setTexture(m_backgroundTexture);

	m_button1.setTexture(m_buttonTex);
	m_button2.setTexture(m_buttonTex);
	m_button3.setTexture(m_buttonTex);

	m_backgroundSprite.setOrigin(450, 300);
	m_backgroundSprite.setPosition(450, 300);
	m_backgroundSprite.setScale(1.04, 1.04);

	m_button1.setPosition(1000, 200);
	m_button2.setPosition(1000, 300);
	m_button3.setPosition(1000, 400);
	m_button1Text.setPosition(1035, 205);
	m_button2text.setPosition(1035, 305);
	m_button3text.setPosition(1035, 405);

}
OptionsScreen::~OptionsScreen()
{
}

void OptionsScreen::update(GamePadState m_state, sf::Time deltaTime, Xbox360Controller2 m_controller)
{
	checkButtonSelected(m_state, m_controller);
	selectedButton(m_state, m_controller);

	if (m_transitionFromMenu)
	{
		if (m_button1.getPosition().x > 370)
		{
			m_button1.setPosition(m_button1.getPosition().x - 1, m_button1.getPosition().y);
			m_button2.setPosition(m_button2.getPosition().x - 1, m_button2.getPosition().y);
			m_button3.setPosition(m_button3.getPosition().x - 1, m_button3.getPosition().y);

			m_button1Text.setPosition(m_button1Text.getPosition().x - 1, m_button1Text.getPosition().y);
			m_button2text.setPosition(m_button2text.getPosition().x - 1, m_button2text.getPosition().y);
			m_button3text.setPosition(m_button3text.getPosition().x - 1, m_button3text.getPosition().y);
		}
		else
		{
			m_transitionFromMenu = false;
		}
	}

	if (m_transitionToMenu)
	{
		if (m_button1.getPosition().x < 1000)
		{
			m_button1.setPosition(m_button1.getPosition().x + 1, m_button1.getPosition().y);
			m_button2.setPosition(m_button2.getPosition().x + 1, m_button2.getPosition().y);
			m_button3.setPosition(m_button3.getPosition().x + 1, m_button3.getPosition().y);

			m_button1Text.setPosition(m_button1Text.getPosition().x + 1, m_button1Text.getPosition().y);
			m_button2text.setPosition(m_button2text.getPosition().x + 1, m_button2text.getPosition().y);
			m_button3text.setPosition(m_button3text.getPosition().x + 1, m_button3text.getPosition().y);
		}
		else
		{
			m_transitionFromMenu = true;
			m_transitionToMenu = false;
			m_game->m_screen = MenuState::MenuScreen;
		}
	}
}

void OptionsScreen::render(sf::RenderWindow & window)
{
	window.clear(sf::Color(220, 20, 60));
	window.draw(m_backgroundSprite);		//Draws text to the screen
	window.draw(m_button1);
	window.draw(m_button2);
	window.draw(m_button3);
	window.draw(m_button1Text);
	window.draw(m_button2text);
	window.draw(m_button3text);
	window.display();	//Displays the screen
}

void OptionsScreen::checkButtonSelected(GamePadState m_state, Xbox360Controller2 m_controller)
{
	switch (m_oButton)
	{
	case Option1:
		m_button1Text.setColor(sf::Color(236, 0, 24));
		m_button2text.setColor(sf::Color(0, 0, 0));
		m_button3text.setColor(sf::Color(0, 0, 0));

		if ((m_state.dpadDown && !m_controller.m_previousState.dpadDown) || (m_state.LeftThumbStick.y > 50 && m_controller.m_previousState.LeftThumbStick.y < 50))
		{
			m_oButton = optionButton::Option2;
		}

		if ((m_state.dpadUp && !m_controller.m_previousState.dpadUp) || (m_state.LeftThumbStick.y < -50 && m_controller.m_previousState.LeftThumbStick.y > -50))
		{
			m_oButton = optionButton::Option3;
		}
		break;
	case Option2:
		m_button1Text.setColor(sf::Color(0, 0, 0));
		m_button2text.setColor(sf::Color(236, 0, 24));
		m_button3text.setColor(sf::Color(0, 0, 0));

		if ((m_state.dpadDown && !m_controller.m_previousState.dpadDown) || (m_state.LeftThumbStick.y > 50 && m_controller.m_previousState.LeftThumbStick.y < 50))
		{
			m_oButton = optionButton::Option3;
		}

		if ((m_state.dpadUp && !m_controller.m_previousState.dpadUp) || (m_state.LeftThumbStick.y < -50 && m_controller.m_previousState.LeftThumbStick.y > -50))
		{
			m_oButton = optionButton::Option1;
		}
		break;
	case Option3:
		m_button1Text.setColor(sf::Color(0, 0, 0));
		m_button2text.setColor(sf::Color(0, 0, 0));
		m_button3text.setColor(sf::Color(236, 0, 24));

		if ((m_state.dpadDown && !m_controller.m_previousState.dpadDown) || (m_state.LeftThumbStick.y > 50 && m_controller.m_previousState.LeftThumbStick.y < 50))
		{
			m_oButton = optionButton::Option1;
		}

		if ((m_state.dpadUp && !m_controller.m_previousState.dpadUp) || (m_state.LeftThumbStick.y < -50 && m_controller.m_previousState.LeftThumbStick.y > -50))
		{
			m_oButton = optionButton::Option2;
		}
		break;
	default:
		break;
	}
}

void OptionsScreen::selectedButton(GamePadState m_state, Xbox360Controller2 m_controller)
{
	switch (m_oButton)
	{
	case Option1:
		break;
	case Option2:
		break;
	case Option3:
		if (m_state.A && !m_controller.m_previousState.A)
		{
			m_transitionToMenu = true;
		}
		break;
	default:
		break;
	}
}