#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include "Xbox360Controller.h"
#include "Game.h"

class Game;

class startScreen
{
public:
	startScreen(Game& game);
	~startScreen();	//De-constructor for the splash screen

	void update(GamePadState m_state);	//Updates the splash screen
	void render();	//Draws the splash screen

private:
	Game *m_game;
	bool m_startPressed = false;
};
#endif // !STARTSCREEN_H

