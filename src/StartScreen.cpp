#include "StartScreen.h"

startScreen::startScreen(Game& game, sf::Font &font) :
	m_game(&game),	// Sets the value in m_game to the address of the game argument.
	m_text("Press Start", font, 32)
{
	if (!m_texture.loadFromFile(".\\resources\\images\\startBG.jpg"))	// Checks that the texture has been loaded into the variable.
	{
		{
			std::string s("Error loading texture");	// Outputs error message.
			throw std::exception(s.c_str());	// Opens a error window with the erro message displayed.
		}
	}
	m_sprite.setTexture(m_texture);	// Sets the texture of the sprite to the one that was just loaded in. 

	if (!m_jackTex.loadFromFile(".\\resources\\images\\Jack.png"))	// Checks that the texture has been loaded into the variable.
	{
		{
			std::string s("Error loading texture");	// Outputs error message.
			throw std::exception(s.c_str());	// Opens a error window with the erro message displayed.
		}
	}
	m_jack.setTexture(m_jackTex);	// Sets the texture of the sprite to the one that was just loaded in.

	if (!m_johnTex.loadFromFile(".\\resources\\images\\John.png"))	// Checks that the texture has been loaded into the variable.
	{
		{
			std::string s("Error loading texture");	// Outputs error message.
			throw std::exception(s.c_str());	// Opens a error window with the erro message displayed.
		}
	}
	m_john.setTexture(m_johnTex);	// Sets the texture of the sprite to the one that was just loaded in.

	m_sprite.setOrigin(450, 300);	// Sets the origin to the centre of screen.
	m_sprite.setPosition(450, 300);	// Sets the position of the sprite to the centre of the screen.

	m_text.setColor(sf::Color(0, 0, 0));	// Sets the colour of the text to black.
	m_text.setPosition(350, 500);	// Sets the position of the text to be bottom middle of the screen.

	m_jack.setOrigin(25, 35);	// Sets the origin of the sprite to be the centre of itself.
	m_john.setOrigin(25, 35);	// Sets the origin of the sprite to be the centre of itself.

	m_jack.setPosition(150, 165);	// Sets Jack's head's position to the left of the title.
	m_john.setPosition(750, 165);	// Sets John's head's position to the right of the title.

	m_jack.scale(2, 2);	// Scales Jack's head.
	m_john.scale(2, 2);	// Scales John's head.
	
}

startScreen::~startScreen()
{

}

void startScreen::update(GamePadState m_state, sf::Time deltaTime)
{
	m_john.setRotation(m_john.getRotation() - 0.2);	// Rotates John's head.
	m_jack.setRotation(m_jack.getRotation() + 0.2);	// Rotates Jack's head.

	if (m_state.Start || sf::Keyboard::isKeyPressed(sf::Keyboard::Return))	// Checks if the player has hit either the start button or the return key. 
	{
		m_startPressed = true;	// Sets the bool to be true once the player presses either start or hits the return key.
	}
	else if (m_state.Back)	// Checks if the player has pressed the back button.
	{
		exit(0);	// Closes the window.
	}

	if (m_startPressed)	// If the start button has been pressed this will execute.
	{
		if (!m_timeStop)	// Checks if m_timeStop is false.
		{
			deltaTime.Zero;	// resets deltaTime.
			m_timeStop = true;	// Sets to true so that deltaTime won't restart again.
		}

		m_sprite.setRotation(m_sprite.getRotation() + 2);	// Rotates the sprite.
		m_sprite.scale(0.999, 0.999);	// Scales down the sprite.
		m_time += TIME_PER_UPDATE;	// Increments the counter.
	}

	if (m_time.asSeconds() > 3)	// Checks that m_time is less then 3 seconds.
	{
		m_game->setGameState(MenuState::MenuScreen);	// Calls the method inside the game object to change game states.
	}
	
}

void startScreen::render(sf::RenderWindow& window)
{
	window.clear(sf::Color(220, 20, 60));	// Clears window.
	window.draw(m_sprite);		// Draws text to the screen.
	if (!m_startPressed)	// Checks whether or not the player has hit start yet.
	{
		window.draw(m_jack);	// Draws Jack's head to the screen.
		window.draw(m_john);	// Draws John's head to the screen.
		window.draw(m_text);	// Draws the text to the screen.
	}
	window.display();	// Displays the screen.
}