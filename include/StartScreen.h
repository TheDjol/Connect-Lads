#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include "Xbox360Controller.h"
#include "Game.h"

class Game;

class startScreen
{
public:
	/// <summary>
	/// Constructor for the start screen,
	/// Takes 2 arguments: the address of the game object and the address of the font file.
	/// </summary>
	/// <param name="game"></param>
	/// <param name="font"></param>
	startScreen(Game& game, sf::Font &font);
	~startScreen();	// Deconstructor for the splash screen

	void update(GamePadState m_state, sf::Time deltaTime);	// Updates the splash screen
	void render(sf::RenderWindow& window);	// Draws the splash screen

private:
	Game *m_game;	// A game object that points to the original.
	bool m_startPressed = false;	// Determines whether the player has pressed start yet.
	sf::Sprite m_sprite;	//	Sprite representing the background.
	sf::Sprite m_jack;	// Sprite representing Jack's head.
	sf::Sprite m_john;	// Sprite representing John's head.

	sf::Texture m_texture;	// The background texture.
	sf::Texture m_jackTex;	// The texture that is Jack's head.
	sf::Texture m_johnTex;	// The texture that is John's head.
	bool m_timeStop = false;	// Detemines whether or not to stop increasing the variable m_time.
	sf::Time m_time;	// Variable that keeps track of how much time has passed between each update.
	const sf::Time TIME_PER_UPDATE = sf::microseconds(1500);	// the number that is added to m_time on each update.
	sf::Text m_text;	// The text that is displayed to the screen.
};
#endif // !STARTSCREEN_H