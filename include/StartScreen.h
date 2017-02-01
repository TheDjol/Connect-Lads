#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include "Xbox360Controller.h"
#include "Game.h"

class Game;

class startScreen
{
public:
	startScreen(Game& game, sf::Font &font);
	~startScreen();	//De-constructor for the splash screen

	void update(GamePadState m_state, sf::Time deltaTime);	//Updates the splash screen
	void render(sf::RenderWindow& window);	//Draws the splash screen

private:
	Game *m_game;
	bool m_startPressed = false;
	sf::Sprite m_sprite;
	sf::Sprite m_jack;
	sf::Sprite m_john;

	sf::Texture m_texture;
	sf::Texture m_jackTex;
	sf::Texture m_johnTex;
	bool m_timeStop = false;
	sf::Time m_time;
	const sf::Time TIME_PER_UPDATE = sf::microseconds(1500);
	sf::Text m_text;
};
#endif // !STARTSCREEN_H