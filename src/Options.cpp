#include "..\include\Options.h"

OptionsScreen::OptionsScreen(Game& game, sf::Font &font) :
	m_game(&game)
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
	m_backgroundSprite.setScale(1.04, 1.04);

}
OptionsScreen::~OptionsScreen()
{
}

void OptionsScreen::update(GamePadState m_state, sf::Time deltaTime, Xbox360Controller2 m_controller)
{
	checkButtonSelected(m_state, m_controller);
	selectedButton(m_state, m_controller);

	if (m_transitionToMenu)
	{
		/*if ((m_playSprite.getPosition().x + m_playSprite.getLocalBounds().width) > 0)
		{
			sf::Vector2f tempVector;

		}*/
		/*else
		{
			m_game->m_screen = MenuState::MenuScreen;
		}*/
	}
}

void OptionsScreen::render(sf::RenderWindow & window)
{
	window.clear(sf::Color(220, 20, 60));
	window.draw(m_backgroundSprite);		//Draws text to the screen


	window.display();	//Displays the screen
}

void OptionsScreen::checkButtonSelected(GamePadState m_state, Xbox360Controller2 m_controller)
{
}

void OptionsScreen::selectedButton(GamePadState m_state, Xbox360Controller2 m_controller)
{
}