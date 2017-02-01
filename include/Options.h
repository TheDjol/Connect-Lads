#pragma once

#ifndef OPTIONS
#define	OPTIONS

#include "Game.h"
#include "Xbox360Controller.h"

class Game;

class OptionsScreen
{
public:
	OptionsScreen(Game& game, sf::Font &font);
	~OptionsScreen();

	void update(GamePadState m_state, sf::Time deltaTime, Xbox360Controller2 m_controller);
	void render(sf::RenderWindow& window);
	void checkButtonSelected(GamePadState m_state, Xbox360Controller2 m_controller);
	void selectedButton(GamePadState m_state, Xbox360Controller2 m_controller);

private:
	Game *m_game;

	bool m_transitionToMenu;
	bool m_transitionFromMenu;
	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;
};

#endif // !OPTIONS
