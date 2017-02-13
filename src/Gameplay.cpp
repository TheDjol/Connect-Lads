#include "..\include\Gameplay.h"

Gameplay::Gameplay(Game& game, sf::Font &font) :
	m_game(&game)
{

	if (!m_backgroundTexture.loadFromFile(".\\resources\\images\\startBG.jpg"))
	{
		{
			std::string s("Error loading texture");	//Outputs error message
			throw std::exception(s.c_str());
		}
	}

	if (!m_buttonTex.loadFromFile(".\\resources\\images\\Button.png"))
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
			m_gameGrid[j][i] = sf::RectangleShape(sf::Vector2f(60, 30));
			m_gameGrid[j][i].setPosition(105 * (i + 1), 100 + (40 * (j + 1)));
		}

	}
}

Gameplay::~Gameplay()
{
}

void Gameplay::update(GamePadState m_state, sf::Time deltaTime, Xbox360Controller2 m_controller)
{
	checkButtonSelected(m_state, m_controller);
	selectedButton(m_state, m_controller);
}

void Gameplay::render(sf::RenderWindow & window)
{
	window.clear(sf::Color(220, 20, 60));	//Clears window
	window.draw(m_backgroundSprite);		//Draws the background to the screen
	
	for (int i = 0; i < 7; i++)
	{
		m_buttons[i].render(window);
	}


	for (int i = 0; i < GAME_GRID_COLUMNS; i++)
	{

		for (int j = 0; j < GAME_GRID_ROWS; j++)
		{
			window.draw(m_gameGrid[j][i]);
		}

	}

	window.display();	//Displays the screen
}

void Gameplay::checkButtonSelected(GamePadState m_state, Xbox360Controller2 m_controller)
{
	buttonChosen(buttonNumber);
	switch (m_buttonSelected)
	{
	case ButtonA:
		if ((m_state.dpadRight && !m_controller.m_previousState.dpadRight) || (m_state.LeftThumbStick.x > 50 && m_controller.m_previousState.LeftThumbStick.x < 50))
		{
			buttonNumber = 1;
			m_buttonSelected = Buttons::ButtonB;
		}
		else if ((m_state.dpadLeft && !m_controller.m_previousState.dpadLeft) || (m_state.LeftThumbStick.x < -50 && m_controller.m_previousState.LeftThumbStick.x > -50))
		{
			buttonNumber = 6;
			m_buttonSelected = Buttons::ButtonG;
		}
		break;
	case ButtonB:
		if ((m_state.dpadRight && !m_controller.m_previousState.dpadRight) || (m_state.LeftThumbStick.x > 50 && m_controller.m_previousState.LeftThumbStick.x < 50))
		{
			buttonNumber = 2;
			m_buttonSelected = Buttons::ButtonC;
		}
		else if ((m_state.dpadLeft && !m_controller.m_previousState.dpadLeft) || (m_state.LeftThumbStick.x < -50 && m_controller.m_previousState.LeftThumbStick.x > -50))
		{
			buttonNumber = 0;
			m_buttonSelected = Buttons::ButtonA;
		}
		break;
	case ButtonC:
		if ((m_state.dpadRight && !m_controller.m_previousState.dpadRight) || (m_state.LeftThumbStick.x > 50 && m_controller.m_previousState.LeftThumbStick.x < 50))
		{
			buttonNumber = 3;
			m_buttonSelected = Buttons::ButtonD;
		}
		else if ((m_state.dpadLeft && !m_controller.m_previousState.dpadLeft) || (m_state.LeftThumbStick.x < -50 && m_controller.m_previousState.LeftThumbStick.x > -50))
		{
			buttonNumber = 1;
			m_buttonSelected = Buttons::ButtonB;
		}
		break;
	case ButtonD:
		if ((m_state.dpadRight && !m_controller.m_previousState.dpadRight) || (m_state.LeftThumbStick.x > 50 && m_controller.m_previousState.LeftThumbStick.x < 50))
		{
			buttonNumber = 4;
			m_buttonSelected = Buttons::ButtonE;
		}
		else if ((m_state.dpadLeft && !m_controller.m_previousState.dpadLeft) || (m_state.LeftThumbStick.x < -50 && m_controller.m_previousState.LeftThumbStick.x > -50))
		{
			buttonNumber = 2;
			m_buttonSelected = Buttons::ButtonC;
		}
		break;
	case ButtonE:
		if ((m_state.dpadRight && !m_controller.m_previousState.dpadRight) || (m_state.LeftThumbStick.x > 50 && m_controller.m_previousState.LeftThumbStick.x < 50))
		{
			buttonNumber = 5;
			m_buttonSelected = Buttons::ButtonF;
		}
		else if ((m_state.dpadLeft && !m_controller.m_previousState.dpadLeft) || (m_state.LeftThumbStick.x < -50 && m_controller.m_previousState.LeftThumbStick.x > -50))
		{
			buttonNumber = 3;
			m_buttonSelected = Buttons::ButtonD;
		}
		break;
	case ButtonF:
		if ((m_state.dpadRight && !m_controller.m_previousState.dpadRight) || (m_state.LeftThumbStick.x > 50 && m_controller.m_previousState.LeftThumbStick.x < 50))
		{
			buttonNumber = 6;
			m_buttonSelected = Buttons::ButtonG;
		}
		else if ((m_state.dpadLeft && !m_controller.m_previousState.dpadLeft) || (m_state.LeftThumbStick.x < -50 && m_controller.m_previousState.LeftThumbStick.x > -50))
		{
			buttonNumber = 4;
			m_buttonSelected = Buttons::ButtonE;
		}
		break;
	case ButtonG:
		if ((m_state.dpadRight && !m_controller.m_previousState.dpadRight) || (m_state.LeftThumbStick.x > 50 && m_controller.m_previousState.LeftThumbStick.x < 50))
		{
			buttonNumber = 0;
			m_buttonSelected = Buttons::ButtonA;
		}
		else if ((m_state.dpadLeft && !m_controller.m_previousState.dpadLeft) || (m_state.LeftThumbStick.x < -50 && m_controller.m_previousState.LeftThumbStick.x > -50))
		{
			buttonNumber = 5;
			m_buttonSelected = Buttons::ButtonF;
		}
		break;
	default:
		break;
	}

}

void Gameplay::selectedButton(GamePadState m_state, Xbox360Controller2 m_controller)
{
	switch (m_buttonSelected)
	{
	case ButtonA:

		break;
	case ButtonB:

		break;
	case ButtonC:

		break;
	case ButtonD:

		break;
	case ButtonE:

		break;
	case ButtonF:

		break;
	case ButtonG:

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
