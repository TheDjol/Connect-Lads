#pragma once

#ifndef OPTIONS
#define	OPTIONS

#include "Game.h"
#include "Xbox360Controller.h"
#include "MainMenu.h"

class Game;

enum optionButton
{
	Option1,
	Option2,
	Option3
};

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
	optionButton m_oButton = optionButton::Option1;
	bool m_transitionToMenu;
	bool m_transitionFromMenu = true;
	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;

	sf::Texture m_buttonTex;

	sf::Sprite m_button1;
	sf::Sprite m_button2;
	sf::Sprite m_button3;

	sf::Text m_button1Text;
	sf::Text m_button2text;
	sf::Text m_button3text;
};

#endif // !OPTIONS
