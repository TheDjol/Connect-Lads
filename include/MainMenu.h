#pragma once

#ifndef MAIN_MENU
#define MAIN_MENU

#include "Game.h"
#include "Xbox360Controller.h"
#include <math.h>

class Game;

class MainMenu
{
public:
	MainMenu(Game& game, sf::Font &font);
	~MainMenu();

	void update(GamePadState m_state, sf::Time deltaTime);	
	void render(sf::RenderWindow& window);

private:
	Game *m_game;
	bool m_timeStop = false;
	sf::Time m_time;
	const sf::Time TIME_PER_UPDATE = sf::microseconds(1500);
	
	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;

	// Shared component of all menu buttons.
	sf::Texture m_buttonTexture;

	// Components of the play button.
	sf::Sprite m_playSprite;
	sf::Text m_playText;
	bool playHighlighted;

	// Components of the options button
	sf::Sprite m_optionsSprite;
	sf::Text m_optionsText;
	bool optionsHighlighted;

	// Components of the exit button.
	sf::Sprite m_exitSprite;
	sf::Text m_exitText;
	bool exitHighlighted;

	const double PI = 2 * acos(0.0);
};
#endif // !MAIN_MENU