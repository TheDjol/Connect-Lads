#pragma once

#ifndef MAIN_MENU
#define MAIN_MENU

#include "Game.h"
#include "Xbox360Controller.h"

class Game;

enum button
{
	Play,
	Options,
	Exit
};

class MainMenu
{
public:
	MainMenu(Game& game, sf::Font &font);
	~MainMenu();

	void update(GamePadState m_state, sf::Time deltaTime, Xbox360Controller2 m_controller);	
	void render(sf::RenderWindow& window);
	void checkButtonSelected(GamePadState m_state, Xbox360Controller2 m_controller);
	void selectedButton(GamePadState m_state, Xbox360Controller2 m_controller);

private:
	const sf::Vector2f WINDOW_DIMENSIONS = sf::Vector2f(900, 600);

	Game *m_game;
	bool m_timeStop = false;
	sf::Time m_time;
	const sf::Time TIME_PER_UPDATE = sf::microseconds(1500);
	button m_button = button::Play;
	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;

	bool m_transitionStop = false;
	bool m_transitionToOptions;
	bool m_transitionFromOptions;
	

	// Shared component of all menu buttons.
	sf::Texture m_buttonTexture;

	// Components of the options button
	sf::Sprite m_optionsSprite;
	sf::Text m_optionsText;

	// Components of the exit button.
	sf::Sprite m_exitSprite;
	sf::Text m_exitText;
};
#endif // !MAIN_MENU