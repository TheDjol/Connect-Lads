/// <summary>
/// @mainpage Button Game -> A game that features a main menu and the gameplay hinges on the use of buttons.
/// @Author D.J. O'Leary and Peter Daly
/// @Version 1.0
/// @brief program that uses buttons for gameplay.
///
/// A program that shows 
/// 
/// Date/ Start time -> End time/ length of time.
/// 23/01/16 / 17:45 -> 19:00 / 
/// 24/01/16 / 14:30 ->
/// 
/// Total Time Taken: 
/// </summary>

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include <iostream>
#include "Game.h"

int main()
{
	Game game;	//the game object
	game.run();	//runs the game

	std::system("PAUSE");
}