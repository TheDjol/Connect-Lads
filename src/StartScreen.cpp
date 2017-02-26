#include "StartScreen.h"

startScreen::startScreen(Game& game, sf::Font &font) :
	m_game(&game),
	m_text("Press Start", font, 32)
{
	if (!m_texture.loadFromFile(".\\resources\\images\\startBG.jpg"))
	{
		{
			std::string s("Error loading texture");	//Outputs error message
			throw std::exception(s.c_str());
		}
	}
	m_sprite.setTexture(m_texture);

	if (!m_jackTex.loadFromFile(".\\resources\\images\\Jack.png"))
	{
		{
			std::string s("Error loading texture");	//Outputs error message
			throw std::exception(s.c_str());
		}
	}
	m_jack.setTexture(m_jackTex);

	if (!m_johnTex.loadFromFile(".\\resources\\images\\John.png"))
	{
		{
			std::string s("Error loading texture");	//Outputs error message
			throw std::exception(s.c_str());
		}
	}
	m_john.setTexture(m_johnTex);

	m_sprite.setOrigin(450, 300);
	m_sprite.setPosition(450, 300);

	m_text.setColor(sf::Color(1, 1, 1));
	m_text.setPosition(350, 500);

	m_jack.setOrigin(25, 35);
	m_john.setOrigin(25, 35);

	m_jack.setPosition(150, 165);
	m_john.setPosition(750, 165);

	m_jack.scale(2, 2);
	m_john.scale(2, 2);
	
}

startScreen::~startScreen()
{

}

void startScreen::update(GamePadState m_state, sf::Time deltaTime)
{
	m_john.setRotation(m_john.getRotation() - 0.2);
	m_jack.setRotation(m_jack.getRotation() + 0.2);
	if (m_state.Start || sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		m_startPressed = true;
	}
	else if (m_state.Back)
	{
		exit(0);
	}

	if (m_startPressed)
	{
		if (!m_timeStop)
		{
			deltaTime.Zero;
			m_timeStop = true;
		}
		m_sprite.setRotation(m_sprite.getRotation() + 2);	//Rotates the sprite
		m_sprite.scale(0.999, 0.999);	//Scales down the sprite
		m_time += TIME_PER_UPDATE;	//Increments the counter
	}

	if (m_time.asSeconds() > 3)
	{
		m_game->setGameState(MenuState::MenuScreen);
	}
	
}

void startScreen::render(sf::RenderWindow& window)
{
	window.clear(sf::Color(220, 20, 60));	//Clears window
	window.draw(m_sprite);		//Draws text to the screen
	if (!m_startPressed)
	{
		window.draw(m_jack);
		window.draw(m_john);
		window.draw(m_text);
	}
	window.display();	//Displays the screen
}