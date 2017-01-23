#include "StartScreen.h"

startScreen::startScreen(Game& game) :
	m_game(&game)
{

}

startScreen::~startScreen()
{

}

void startScreen::update(GamePadState m_state)
{
	if (m_state.Start)
	{
		m_startPressed = true;
	}

	if (m_startPressed)
	{
		m_game->setGameState(MenuState::menuScreen);
	}
	
}

void startScreen::render()
{

}