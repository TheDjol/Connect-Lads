#include "..\include\Gameplay.h"

Gameplay::Gameplay(Game& game, sf::Font &font) :
	m_game(&game)
{
}

Gameplay::~Gameplay()
{
}

void Gameplay::update(GamePadState m_state, sf::Time deltaTime, Xbox360Controller2 m_controller)
{
}

void Gameplay::render(sf::RenderWindow & window)
{
}

void Gameplay::checkButtonSelected(GamePadState m_state, Xbox360Controller2 m_controller)
{
	switch (m_buttonSelected)
	{
	case ButtonA:
		if ((m_state.dpadRight && !m_controller.m_previousState.dpadRight) || (m_state.LeftThumbStick.x > 50 && m_controller.m_previousState.LeftThumbStick.x < 50))
		{
			m_buttonSelected = ButtonA;
		}
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
