#include "..\include\Gameplay.h"

Gameplay::Gameplay(Game& game, sf::Font &font) :
	m_game(&game),
	m_font(font),
	m_return("Press the back button to return to menu.", m_font, 32),
	m_winner("", m_font, 32)
{
	// Loads the background texture
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


	m_return.setPosition(150, 25);	// Sets the position of the return text
	m_backgroundSprite.setTexture(m_backgroundTexture);	// Sets the texture of the background sprite
	m_backgroundSprite.setPosition(0, 0);	// Sets the position of the background sprite

	// Loads the button texture
	if (!m_buttonTex.loadFromFile(".\\resources\\images\\Button.png"))
	{
		{
			std::string s("Error loading texture");	//Outputs error message
			throw std::exception(s.c_str());
		}
	}

	// Loads the blank texture
	if (!m_blankTexture.loadFromFile(".\\resources\\images\\Blank.png"))
	{
		{
			std::string s("Error loading texture");	//Outputs error message
			throw std::exception(s.c_str());
		}
	}

	std::string buttonText[7] = { "A", "B", "C", "D", "E", "F", "G" };	// An array of strings for each button
	
	for (int i = 0; i < SIZE_OF_BUTTON_ARRAY; i++)	// Cycles through each button 
	{
		m_buttons[i] = Button(&m_buttonTex, &buttonText[i], &sf::Vector2f(113 * (i + 1), 100), &font);	// Constructs the buttons
		m_buttons[i].scaleButtons(0.8f, 1.0f);	// Scales the buttons
	}

	// Double for loop to cycle through each rectangle shape
	for (int i = 0; i < GAME_GRID_COLUMNS; i++)
	{

		for (int j = 0; j < GAME_GRID_ROWS; j++)
		{
			m_gameGrid[j][i] = sf::RectangleShape(sf::Vector2f(100, 60));	// Sets the dimensions of the rectangle
			m_gameGrid[j][i].setPosition (((105 * (i + 1) - 25)), 100 + (70 * (j + 1)));	// Sets the position of each one
			m_gameGrid[j][i].setOutlineColor(sf::Color::Black);	// Sets the colour of the outline of the rectangle shapes
			m_gameGrid[j][i].setOutlineThickness(2.0f);	// Sets the line thickness of the rectangle shapes
			m_headSprite[j][i].setPosition(m_gameGrid[j][i].getPosition().x + 25, m_gameGrid[j][i].getPosition().y - 10);	// Sets the position of all the head sprites
		}

	}
}

Gameplay::~Gameplay()
{
}

// Function to render the game screen 
void Gameplay::update(GamePadState m_state, sf::Time deltaTime, Xbox360Controller2 m_controller)
{
	srand(time(NULL));
	/* generate secret number between 0 and 3: */
	m_randomHead = rand() % 4 + 0;
	checkButtonSelected(m_state, m_controller);	// Calls the function to check which button is selected

	if (m_state.Back)	// Checks if the back button has been pressed
	{
		// Double for loop to cycle through each rectangle shape
		for (int i = 0; i < GAME_GRID_COLUMNS; i++)
		{

			for (int j = 0; j < GAME_GRID_ROWS; j++)
			{
				m_headSprite[j][i].setTexture(m_blankTexture);	// Sets the head textures to be blank
				m_gameGrid[j][i].setFillColor(sf::Color::White);	// Sets the colour of each rectangle to be white
			}

		}
		m_victory = false;	// Sets the winner to be false
		m_winner = sf::Text("", m_font, 32);	// Initializes the winner text object
		m_game->m_screen = MenuState::MenuScreen;	// Sets the game screen to be the menu screen
	}
}

// Function to render the game screen
void Gameplay::render(sf::RenderWindow & window)
{
	window.clear(sf::Color(220, 20, 60));	// Clears window
	window.draw(m_backgroundSprite);		// Draws the background to the screen
	window.draw(m_winner);	// Draws the victory text.
	window.draw(m_return);	// Draws the return text.

	// Cycles through the buttons
	for (int i = 0; i < 7; i++)
	{
		m_buttons[i].render(window);	// Renders the buttons 
	}

	// Double for loop to cycle through each rectangle shape
	for (int i = 0; i < GAME_GRID_COLUMNS; i++)
	{

		for (int j = 0; j < GAME_GRID_ROWS; j++)
		{
			window.draw(m_gameGrid[j][i]);	// Draws the game grid
			window.draw(m_headSprite[j][i]);	// Draws the head sprites
		}

	}

	window.display();	// Displays the screen
}

// Function to check which button is selected
void Gameplay::checkButtonSelected(GamePadState m_state, Xbox360Controller2 m_controller)
{
	// Checks if the A button has been pressed
	if (m_state.A && !m_controller.m_previousState.A && !m_victory)
	{
		addToColumn(m_buttonNumber);	// Adds to the selected column
	}
	buttonChosen(m_buttonNumber);	// Calls the button chosen function
	switch (m_buttonSelected)	// Switch statement for each button 
	{
	case ButtonA:
		// Checks if the right button has been pressed
		if ((m_state.dpadRight && !m_controller.m_previousState.dpadRight) || (m_state.LeftThumbStick.x > 50 && m_controller.m_previousState.LeftThumbStick.x < 50))
		{
			m_buttonNumber = 1;
			m_buttonSelected = Buttons::ButtonB;	// Switches to the next button
		}
		// Checks if the left button has been pressed
		else if ((m_state.dpadLeft && !m_controller.m_previousState.dpadLeft) || (m_state.LeftThumbStick.x < -50 && m_controller.m_previousState.LeftThumbStick.x > -50))
		{
			m_buttonNumber = 6;
			m_buttonSelected = Buttons::ButtonG;	// Switches to the next button
		}
		break;
	case ButtonB:
		// Checks if the right button has been pressed
		if ((m_state.dpadRight && !m_controller.m_previousState.dpadRight) || (m_state.LeftThumbStick.x > 50 && m_controller.m_previousState.LeftThumbStick.x < 50))
		{
			m_buttonNumber = 2;
			m_buttonSelected = Buttons::ButtonC;	// Switches to the next button
		}
		// Checks if the left button has been pressed
		else if ((m_state.dpadLeft && !m_controller.m_previousState.dpadLeft) || (m_state.LeftThumbStick.x < -50 && m_controller.m_previousState.LeftThumbStick.x > -50))
		{
			m_buttonNumber = 0;
			m_buttonSelected = Buttons::ButtonA;	// Switches to the next button
		}
		break;
	case ButtonC:
		// Checks if the right button has been pressed
		if ((m_state.dpadRight && !m_controller.m_previousState.dpadRight) || (m_state.LeftThumbStick.x > 50 && m_controller.m_previousState.LeftThumbStick.x < 50))
		{
			m_buttonNumber = 3;
			m_buttonSelected = Buttons::ButtonD;	// Switches to the next button
		}
		// Checks if the left button has been pressed
		else if ((m_state.dpadLeft && !m_controller.m_previousState.dpadLeft) || (m_state.LeftThumbStick.x < -50 && m_controller.m_previousState.LeftThumbStick.x > -50))
		{
			m_buttonNumber = 1;
			m_buttonSelected = Buttons::ButtonB;	// Switches to the next button
		}
		break;
	case ButtonD:
		// Checks if the right button has been pressed
		if ((m_state.dpadRight && !m_controller.m_previousState.dpadRight) || (m_state.LeftThumbStick.x > 50 && m_controller.m_previousState.LeftThumbStick.x < 50))
		{
			m_buttonNumber = 4;
			m_buttonSelected = Buttons::ButtonE;	// Switches to the next button
		}
		// Checks if the left button has been pressed
		else if ((m_state.dpadLeft && !m_controller.m_previousState.dpadLeft) || (m_state.LeftThumbStick.x < -50 && m_controller.m_previousState.LeftThumbStick.x > -50))
		{
			m_buttonNumber = 2;
			m_buttonSelected = Buttons::ButtonC;	// Switches to the next button
		}
		break;
	case ButtonE:
		// Checks if the right button has been pressed
		if ((m_state.dpadRight && !m_controller.m_previousState.dpadRight) || (m_state.LeftThumbStick.x > 50 && m_controller.m_previousState.LeftThumbStick.x < 50))
		{
			m_buttonNumber = 5;
			m_buttonSelected = Buttons::ButtonF;	// Switches to the next button
		}
		// Checks if the left button has been pressed
		else if ((m_state.dpadLeft && !m_controller.m_previousState.dpadLeft) || (m_state.LeftThumbStick.x < -50 && m_controller.m_previousState.LeftThumbStick.x > -50))
		{
			m_buttonNumber = 3;
			m_buttonSelected = Buttons::ButtonD;	// Switches to the next button
		}
		break;
	case ButtonF:
		// Checks if the right button has been pressed
		if ((m_state.dpadRight && !m_controller.m_previousState.dpadRight) || (m_state.LeftThumbStick.x > 50 && m_controller.m_previousState.LeftThumbStick.x < 50))
		{
			m_buttonNumber = 6;
			m_buttonSelected = Buttons::ButtonG;	// Switches to the next button
		}
		// Checks if the left button has been pressed
		else if ((m_state.dpadLeft && !m_controller.m_previousState.dpadLeft) || (m_state.LeftThumbStick.x < -50 && m_controller.m_previousState.LeftThumbStick.x > -50))
		{
			m_buttonNumber = 4;
			m_buttonSelected = Buttons::ButtonE;	// Switches to the next button
		}
		break;
	case ButtonG:
		// Checks if the right button has been pressed
		if ((m_state.dpadRight && !m_controller.m_previousState.dpadRight) || (m_state.LeftThumbStick.x > 50 && m_controller.m_previousState.LeftThumbStick.x < 50))
		{
			m_buttonNumber = 0;
			m_buttonSelected = Buttons::ButtonA;	// Switches to the next button
		}
		// Checks if the left button has been pressed
		else if ((m_state.dpadLeft && !m_controller.m_previousState.dpadLeft) || (m_state.LeftThumbStick.x < -50 && m_controller.m_previousState.LeftThumbStick.x > -50))
		{
			m_buttonNumber = 5;
			m_buttonSelected = Buttons::ButtonF;	// Switches to the next button
		}
		break;
	default:
		break;
	}

}

// Function to see which button has been chosen 
void Gameplay::buttonChosen(int buttonNumber)
{
	// Checks the button number
	if (buttonNumber == 0)
	{
		m_buttons[0].getFocus();	// Highlights that button 
	}
	else
		m_buttons[0].loseFocus();	// Sets it to be normal
	// Checks the button number
	if (buttonNumber == 1)
	{
		m_buttons[1].getFocus();	// Highlights that button 
	}
	else
		m_buttons[1].loseFocus();	// Sets it to be normal
	// Checks the button number
	if (buttonNumber == 2)
	{
		m_buttons[2].getFocus();	// Highlights that button 
	}
	else
		m_buttons[2].loseFocus();	// Sets it to be normal
	// Checks the button number
	if (buttonNumber == 3)
	{
		m_buttons[3].getFocus();	// Highlights that button 
	}
	else
		m_buttons[3].loseFocus();	// Sets it to be normal
	// Checks the button number
	if (buttonNumber == 4)
	{
		m_buttons[4].getFocus();	// Highlights that button 
	}
	else
		m_buttons[4].loseFocus();	// Sets it to be normal
	// Checks the button number
	if (buttonNumber == 5)
	{
		m_buttons[5].getFocus();	// Highlights that button 
	}
	else
		m_buttons[5].loseFocus();	// Sets it to be normal
	// Checks the button number	
	if (buttonNumber == 6)
	{
		m_buttons[6].getFocus();	// Highlights that button 
	}
	else
		m_buttons[6].loseFocus();	// Sets it to be normal
}

// Function to add a block to a column
void Gameplay::addToColumn(int buttonNumber)
{
	int counter = 0;	// Sets counter to zero
	for (int j = 5; j >= 0; j--)	// Cycles through the column
	{
		if (m_gameGrid[j][buttonNumber].getFillColor() == sf::Color::White && counter == 0 && m_player)	// Checks if the rectangle is empty and its the blue players turn
		{
			m_gameGrid[j][buttonNumber].setFillColor(sf::Color::Blue);	// Changes the block to be blue
			counter++;	// Increments the counter 
			m_player = false;	// Swaps to the next player
			checkArray(j, buttonNumber, sf::Color::Blue);	// Checks the array to see if the player won
			m_headSprite[j][buttonNumber].setTexture(m_headTexture[m_randomHead]);	// Adds a head to the rectangle
			break;
		}

		else if (m_gameGrid[j][buttonNumber].getFillColor() == sf::Color::White && counter == 0 && !m_player)	// Checks if the rectangle is empty and its the red players turn
		{
			m_gameGrid[j][buttonNumber].setFillColor(sf::Color::Red);	// Changes the block to be red
			counter++;	// Increments the counter 
			m_player = true;	// Swaps to the next player
			checkArray(j, buttonNumber, sf::Color::Red);	// Checks the array to see if the player won
			m_headSprite[j][buttonNumber].setTexture(m_headTexture[m_randomHead]);	// Adds a head to the rectangle
			break;
		}
	}
}

// Function to check the array to see if there is a possibility of victory
void Gameplay::checkArray(int row, int column, sf::Color colour)
{
	// Double for loop to cycle through each rectangle shape
	for (int i = 0; i < GAME_GRID_COLUMNS; i++)
	{
		for (int j = 0; j < GAME_GRID_ROWS; j++)
		{
			m_gameGridColour[j][i] = m_gameGrid[j][i].getFillColor();	// Gets the current colour set up of the board
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

// Function to check a line to see if the player has won
void Gameplay::checkLine(int row, int column, int direction1, sf::Color colour)
{
	int counter = -1;

	/*
		All The for loops cycle through the rectangle shapes
		in the direction based on which direction integer has been passed.
		If the touching shape is of the same colour, the counter will be 
		incremented;.
	*/

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

	// If the blue player has won
	if (counter >= 4 && colour == sf::Color::Blue)
	{
		m_winner = sf::Text("Blue wins", m_font, 32);	// Constructs the winner text
		m_winner.setPosition(380, 130);	// Sets up the winner text with a position
		m_victory = true;	// Sets the game to have been won
	}

	// If the red player has won
	if (counter >= 4 && colour == sf::Color::Red)
	{
		m_winner = sf::Text("Red wins", m_font, 32);	// Constructs the winner text
		m_winner.setPosition(380, 130); // Sets up the winner text with a position
		m_victory = true;	// Sets the game to have been won
	}
}