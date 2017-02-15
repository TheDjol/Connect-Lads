#include "..\include\Gameplay.h"

Gameplay::Gameplay(Game& game, sf::Font &font) :
	m_game(&game),
	m_font(font),
	m_return("Press the back button to return to menu.", m_font, 32),
	m_winner("", m_font, 32)
{

	if (!m_backgroundTexture.loadFromFile(".\\resources\\images\\gameBG.png"))
	{
		{
			std::string s("Error loading texture");	//Outputs error message
			throw std::exception(s.c_str());
		}
	}

	// Stores larrys head.
	m_headTexture[0].loadFromFile(".\\resources\\images\\Larry.png");
	// Stores Johns head.
	m_headTexture[1].loadFromFile(".\\resources\\images\\John.png");
	// Stores Jacks head.
	m_headTexture[2].loadFromFile(".\\resources\\images\\Jack.png");
	// Stores  head.
	m_headTexture[3].loadFromFile(".\\resources\\images\\Darren.png");


	m_return.setPosition(150, 25);
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setPosition(0, 0);

	if (!m_buttonTex.loadFromFile(".\\resources\\images\\Button.png"))
	{
		{
			std::string s("Error loading texture");	//Outputs error message
			throw std::exception(s.c_str());
		}
	}

	if (!m_blankTexture.loadFromFile(".\\resources\\images\\Blank.png"))
	{
		{
			std::string s("Error loading texture");	//Outputs error message
			throw std::exception(s.c_str());
		}
	}

	std::string buttonText[7] = { "A", "B", "C", "D", "E", "F", "G" };
	
	for (int i = 0; i < SIZE_OF_BUTTON_ARRAY; i++)
	{
		m_buttons[i] = Button(&m_buttonTex, &buttonText[i], &sf::Vector2f(113 * (i + 1), 100), &font);
		m_buttons[i].scaleButtons(0.8f, 1.0f);
	}

	for (int i = 0; i < GAME_GRID_COLUMNS; i++)
	{

		for (int j = 0; j < GAME_GRID_ROWS; j++)
		{
			m_gameGrid[j][i] = sf::RectangleShape(sf::Vector2f(100, 60));
			m_gameGrid[j][i].setPosition (((105 * (i + 1) - 25)), 100 + (70 * (j + 1)));
			m_gameGrid[j][i].setOutlineColor(sf::Color::Black);
			m_gameGrid[j][i].setOutlineThickness(2.0f);
			m_headSprite[j][i].setPosition(m_gameGrid[j][i].getPosition().x + 25, m_gameGrid[j][i].getPosition().y - 10);
			
		}

	}
}

Gameplay::~Gameplay()
{
}

void Gameplay::update(GamePadState m_state, sf::Time deltaTime, Xbox360Controller2 m_controller)
{
	checkButtonSelected(m_state, m_controller);

	if (m_state.Back)
	{
		for (int i = 0; i < GAME_GRID_COLUMNS; i++)
		{

			for (int j = 0; j < GAME_GRID_ROWS; j++)
			{
				m_headSprite[j][i].setTexture(m_blankTexture);
				m_gameGrid[j][i].setFillColor(sf::Color::White);
			}

		}
		m_victory = false;
		m_winner = sf::Text("", m_font, 32);
		m_game->m_screen = MenuState::MenuScreen;
	}
}

void Gameplay::render(sf::RenderWindow & window)
{
	window.clear(sf::Color(220, 20, 60));	// Clears window
	window.draw(m_backgroundSprite);		// Draws the background to the screen
	window.draw(m_winner);	// Draws the victory text.
	window.draw(m_return);

	for (int i = 0; i < 7; i++)
	{
		m_buttons[i].render(window);
	}


	for (int i = 0; i < GAME_GRID_COLUMNS; i++)
	{

		for (int j = 0; j < GAME_GRID_ROWS; j++)
		{
			window.draw(m_gameGrid[j][i]);
			window.draw(m_headSprite[j][i]);
		}

	}

	window.display();	// Displays the screen
}

void Gameplay::checkButtonSelected(GamePadState m_state, Xbox360Controller2 m_controller)
{
	if (m_state.A && !m_controller.m_previousState.A && !m_victory)
	{
		addToColumn(m_buttonNumber);
	}
	buttonChosen(m_buttonNumber);
	switch (m_buttonSelected)
	{
	case ButtonA:
		
		if ((m_state.dpadRight && !m_controller.m_previousState.dpadRight) || (m_state.LeftThumbStick.x > 50 && m_controller.m_previousState.LeftThumbStick.x < 50))
		{
			m_buttonNumber = 1;
			m_buttonSelected = Buttons::ButtonB;
		}
		else if ((m_state.dpadLeft && !m_controller.m_previousState.dpadLeft) || (m_state.LeftThumbStick.x < -50 && m_controller.m_previousState.LeftThumbStick.x > -50))
		{
			m_buttonNumber = 6;
			m_buttonSelected = Buttons::ButtonG;
		}
		break;
	case ButtonB:
		if ((m_state.dpadRight && !m_controller.m_previousState.dpadRight) || (m_state.LeftThumbStick.x > 50 && m_controller.m_previousState.LeftThumbStick.x < 50))
		{
			m_buttonNumber = 2;
			m_buttonSelected = Buttons::ButtonC;
		}
		else if ((m_state.dpadLeft && !m_controller.m_previousState.dpadLeft) || (m_state.LeftThumbStick.x < -50 && m_controller.m_previousState.LeftThumbStick.x > -50))
		{
			m_buttonNumber = 0;
			m_buttonSelected = Buttons::ButtonA;
		}
		break;
	case ButtonC:
		if ((m_state.dpadRight && !m_controller.m_previousState.dpadRight) || (m_state.LeftThumbStick.x > 50 && m_controller.m_previousState.LeftThumbStick.x < 50))
		{
			m_buttonNumber = 3;
			m_buttonSelected = Buttons::ButtonD;
		}
		else if ((m_state.dpadLeft && !m_controller.m_previousState.dpadLeft) || (m_state.LeftThumbStick.x < -50 && m_controller.m_previousState.LeftThumbStick.x > -50))
		{
			m_buttonNumber = 1;
			m_buttonSelected = Buttons::ButtonB;
		}
		break;
	case ButtonD:
		if ((m_state.dpadRight && !m_controller.m_previousState.dpadRight) || (m_state.LeftThumbStick.x > 50 && m_controller.m_previousState.LeftThumbStick.x < 50))
		{
			m_buttonNumber = 4;
			m_buttonSelected = Buttons::ButtonE;
		}
		else if ((m_state.dpadLeft && !m_controller.m_previousState.dpadLeft) || (m_state.LeftThumbStick.x < -50 && m_controller.m_previousState.LeftThumbStick.x > -50))
		{
			m_buttonNumber = 2;
			m_buttonSelected = Buttons::ButtonC;
		}
		break;
	case ButtonE:
		if ((m_state.dpadRight && !m_controller.m_previousState.dpadRight) || (m_state.LeftThumbStick.x > 50 && m_controller.m_previousState.LeftThumbStick.x < 50))
		{
			m_buttonNumber = 5;
			m_buttonSelected = Buttons::ButtonF;
		}
		else if ((m_state.dpadLeft && !m_controller.m_previousState.dpadLeft) || (m_state.LeftThumbStick.x < -50 && m_controller.m_previousState.LeftThumbStick.x > -50))
		{
			m_buttonNumber = 3;
			m_buttonSelected = Buttons::ButtonD;
		}
		break;
	case ButtonF:
		if ((m_state.dpadRight && !m_controller.m_previousState.dpadRight) || (m_state.LeftThumbStick.x > 50 && m_controller.m_previousState.LeftThumbStick.x < 50))
		{
			m_buttonNumber = 6;
			m_buttonSelected = Buttons::ButtonG;
		}
		else if ((m_state.dpadLeft && !m_controller.m_previousState.dpadLeft) || (m_state.LeftThumbStick.x < -50 && m_controller.m_previousState.LeftThumbStick.x > -50))
		{
			m_buttonNumber = 4;
			m_buttonSelected = Buttons::ButtonE;
		}
		break;
	case ButtonG:
		if ((m_state.dpadRight && !m_controller.m_previousState.dpadRight) || (m_state.LeftThumbStick.x > 50 && m_controller.m_previousState.LeftThumbStick.x < 50))
		{
			m_buttonNumber = 0;
			m_buttonSelected = Buttons::ButtonA;
		}
		else if ((m_state.dpadLeft && !m_controller.m_previousState.dpadLeft) || (m_state.LeftThumbStick.x < -50 && m_controller.m_previousState.LeftThumbStick.x > -50))
		{
			m_buttonNumber = 5;
			m_buttonSelected = Buttons::ButtonF;
		}
		break;
	default:
		break;
	}

}

void Gameplay::buttonChosen(int buttonNumber)
{
	if (buttonNumber == 0)
	{
		m_buttons[0].getFocus();
	}
	else
		m_buttons[0].loseFocus();

	if (buttonNumber == 1)
	{
		m_buttons[1].getFocus();
	}
	else
		m_buttons[1].loseFocus();

	if (buttonNumber == 2)
	{
		m_buttons[2].getFocus();
	}
	else
		m_buttons[2].loseFocus();

	if (buttonNumber == 3)
	{
		m_buttons[3].getFocus();
	}
	else
		m_buttons[3].loseFocus();

	if (buttonNumber == 4)
	{
		m_buttons[4].getFocus();
	}
	else
		m_buttons[4].loseFocus();

	if (buttonNumber == 5)
	{
		m_buttons[5].getFocus();
	}
	else
		m_buttons[5].loseFocus();

	if (buttonNumber == 6)
	{
		m_buttons[6].getFocus();
	}
	else
		m_buttons[6].loseFocus();
}

void Gameplay::addToColumn(int buttonNumber)
{
	int counter = 0;
	for (int j = 5; j >= 0; j--)
	{
		if (m_gameGrid[j][buttonNumber].getFillColor() == sf::Color::White && counter == 0 && m_player)
		{
			m_gameGrid[j][buttonNumber].setFillColor(sf::Color::Blue);
			counter++;
			m_player = false;
			checkArray(j, buttonNumber, sf::Color::Blue);
			m_headSprite[j][buttonNumber].setTexture(m_headTexture[2]);
			break;
		}

		else if (m_gameGrid[j][buttonNumber].getFillColor() == sf::Color::White && counter == 0 && !m_player)
		{
			m_gameGrid[j][buttonNumber].setFillColor(sf::Color::Red);
			counter++;
			m_player = true;
			checkArray(j, buttonNumber, sf::Color::Red);
			m_headSprite[j][buttonNumber].setTexture(m_headTexture[1]);
			break;
		}
	}
}

void Gameplay::checkArray(int row, int column, sf::Color colour)
{
	for (int i = 0; i < GAME_GRID_COLUMNS; i++)
	{
		for (int j = 0; j < GAME_GRID_ROWS; j++)
		{
			m_gameGridColour[j][i] = m_gameGrid[j][i].getFillColor();
		}
	}

	// Checks square Up one, left one of the newest block
	if (m_gameGridColour[row - 1][column - 1] == colour)
	{
		checkLine(row, column, 0, colour);
	}

	// Checks square left one of the newest block
	if (m_gameGridColour[row][column - 1] == colour)
	{
		checkLine(row, column, 3, colour);
	}

	// Checks square down one, left one of the newest block
	if (m_gameGridColour[row + 1][column - 1] == colour)
	{
		checkLine(row, column, 2, colour);
	}

	// Checks square Up one of the newest block
	if (m_gameGridColour[row - 1][column] == colour)
	{
		checkLine(row, column, 1, colour);
	}

	// Checks square down one of the newest block
	if (m_gameGridColour[row + 1][column] == colour)
	{
		checkLine(row, column, 1, colour);
	}

	// Checks square Up one, right one of the newest block
	if (m_gameGridColour[row - 1][column + 1] == colour)
	{
		checkLine(row, column, 2, colour);
	}

	// Checks square right one of the newest block
	if (m_gameGridColour[row][column + 1] == colour)
	{
		checkLine(row, column, 3, colour);
	}

	// Checks square down one, right one of the newest block
	if (m_gameGridColour[row + 1][column + 1] == colour)
	{
		checkLine(row, column, 0, colour);
	}
}

void Gameplay::checkLine(int row, int column, int direction1, sf::Color colour)
{
	int counter = -1;
	if (direction1 == 0)	//Represents diagonal from top left to bottom right
	{
		for (int i = 0; row - i >= 0 && column - i >= 0; i++)
		{
			if (m_gameGridColour[row - i][column - i] == colour)
			{
				counter++;
			}
			else
				break;
		}

		for (int i = 0; row + i < GAME_GRID_ROWS && column + i < GAME_GRID_COLUMNS; i++)
		{
			if (m_gameGridColour[row + i][column + i] == colour)
			{
				counter++;
			}
			else
				break;
		}
	}

	if (direction1 == 1)	//Represents from top to bottom
	{
		for (int i = 0; row - i >= 0 ; i++)
		{
			if (m_gameGridColour[row - i][column] == colour)
			{
				counter++;
			}
			else
				break;
		}

		for (int i = 0; row + i < GAME_GRID_ROWS; i++)
		{
			if (m_gameGridColour[row + i][column] == colour)
			{
				counter++;
			}
			else
				break;
		}
	}

	if (direction1 == 2)	//Represents diagonal from top right to bottom left
	{
		for (int i = 0; row - i >= 0 && column + i < GAME_GRID_ROWS; i++)
		{
			if (m_gameGridColour[row - i][column + i] == colour)
			{
				counter++;
			}
			else
				break;
		}

		for (int i = 0; row + i < GAME_GRID_ROWS && column - i >= 0; i++)
		{
			if (m_gameGridColour[row + i][column - i] == colour)
			{
				counter++;
			}
			else
				break;
		}
	}

	if (direction1 == 3)	//Represents from right to left
	{
		for (int i = 0; column - i >= 0; i++)
		{
			if (m_gameGridColour[row][column - i] == colour)
			{
				counter++;
			}
			else
				break;
		}

		for (int i = 0; column + i < GAME_GRID_COLUMNS; i++)
		{
			if (m_gameGridColour[row][column + i] == colour)
			{
				counter++;
			}
			else
				break;
		}
	}

	if (counter >= 4 && colour == sf::Color::Blue)
	{
		m_winner = sf::Text("Blue wins", m_font, 32);
		m_winner.setPosition(380, 130);
		m_victory = true;
	}

	if (counter >= 4 && colour == sf::Color::Red)
	{
		m_winner = sf::Text("Red wins", m_font, 32);
		m_winner.setPosition(380, 130);
		m_victory = true;
	}
}