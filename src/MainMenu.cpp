#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu(Game& game, sf::Font &font) :
	m_game(&game)
{
	// Loads in the background texture
	if (!m_backgroundTexture.loadFromFile(".\\resources\\images\\startBG.jpg"))
	{
		{
			std::string s("Error loading texture");	//Outputs error message
			throw std::exception(s.c_str());
		}
	}

	// Loads in the button texture
	if (!m_buttonTexture.loadFromFile(".\\resources\\images\\Button.png"))
	{
		{
			std::string s("Error loading texture");	//Outputs error message
			throw std::exception(s.c_str());
		}
	}

	// The three strings for the three buttons
	std::string play = "PLAY";
	std::string option = "OPTIONS";
	std::string exit = "EXIT";
	
	// Initializing the three buttons with their texture, string, position and font
	m_buttons[0] = Button(&m_buttonTexture, &play, &sf::Vector2f(450, 200), &font);
	m_buttons[1] = Button(&m_buttonTexture, &option, &sf::Vector2f(450, 300), &font);
	m_buttons[2] = Button(&m_buttonTexture, &exit, &sf::Vector2f(450, 400), &font);

	m_backgroundSprite.setTexture(m_backgroundTexture);	// Sets the background texture

	// Sets the starting position of the background sprite
	m_backgroundSprite.setOrigin(450, 300);
	m_backgroundSprite.setPosition(450, 300);
	m_backgroundSprite.setScale(0.094f, 0.094f);
	m_backgroundSprite.setRotation(122.0f);

}

MainMenu::~MainMenu() 
{

}

// Function to update the main menu
void MainMenu::update(GamePadState m_state, sf::Time deltaTime, Xbox360Controller2 m_controller)
{
	if (m_transitionStop)	// Checks if the starting transition has stopped
	{
		checkButtonSelected(m_state, m_controller);	// Calls the function to check which button is selected
		selectedButton(m_state, m_controller);	// Calls the function to update the selected function
	}

	if (m_state.Back && !m_state.Back)	// Checks if the player has hit the back button
	{
		exit(0);	// Exits the game
	}

	// This if statement is a switch to zero deltatime once when the main menu starts
	if (!m_timeStop) 
	{
		deltaTime.Zero;
		m_timeStop = true;
	}
	
	if (m_time.asSeconds() <= 3.6)	// Checks if theres still time left in the transition
	{
		m_backgroundSprite.setRotation(m_backgroundSprite.getRotation() - 2);	// Rotates the sprite
		m_backgroundSprite.scale(1.001, 1.001);	// Scales up the sprite
		m_time += TIME_PER_UPDATE;	// Increments the counter
	}
	else
	{
		m_transitionStop = true;	// Sets the transition to stop if the correct amount of time has passed
	}

	if (m_transitionToOptions)	// Checks if the menu is transitioning to options
	{
		if ((m_buttons[0].m_sprite.getPosition().x + m_buttons[0].m_sprite.getLocalBounds().width) > 0)	// Checks if the buttons are still on screen
		{
			for (int i = 0; i < 3; i++)
			{
				m_buttons[i].moveLeft();	// Moves all the buttons left
			}
			
		}
		else   // If the transition is finished
		{
			m_transitionToOptions = false;	// Sets the transition to stop
			m_transitionFromOptions = true; // Sets this to be true so that when the player comes back from the options, the menu is set to transition in
			m_game->m_screen = MenuState::OptionScreen;	// Sets the game screen to the options screen
		}
	}

	if (m_transitionFromOptions)	// Checks if the menu is transitioning from options
	{
		if (m_buttons[0].m_sprite.getPosition().x < 410)	// Checks if the buttons are in the right place
		{
			for (int i = 0; i < 3; i++)
			{
				m_buttons[i].moveRight();	// Moves the buttons to the right
			}
		}
		else
		{
			m_transitionFromOptions = false; // Stops the transition
		}
	}


}

// Render function
void MainMenu::render(sf::RenderWindow & window)
{
	window.clear(sf::Color(220, 20, 60));	//Clears window
	window.draw(m_backgroundSprite);		//Draws the background to the screen
	if (m_transitionStop)	// Checks if the menu isnt transitioning
	{
		for (int i = 0; i < 3; i++)
		{
			m_buttons[i].render(window);	// Renders all the buttons
		}
	}
	window.display();	//Displays the screen
}

// Function to check which button is selected
void MainMenu::checkButtonSelected(GamePadState m_state, Xbox360Controller2 m_controller)
{
	switch (m_buttonSelected)	// Switch statement for every button
	{
		
	case button::Play:	// The play button

		// Sets the play button to be highlighted and the other buttons to be not
		m_buttons[0].getFocus();
		m_buttons[1].loseFocus();
		m_buttons[2].loseFocus();
		
		// Checks if the down button has been pressed
		if ((m_state.dpadDown && !m_controller.m_previousState.dpadDown) || (m_state.LeftThumbStick.y > 50 && m_controller.m_previousState.LeftThumbStick.y < 50))
		{
			m_buttonSelected = button::Options;	// Switches to the options button
		}
		
		// Checks if the up button has been pressed
		if ((m_state.dpadUp && !m_controller.m_previousState.dpadUp) || (m_state.LeftThumbStick.y < -50 && m_controller.m_previousState.LeftThumbStick.y > -50))
		{
			m_buttonSelected = button::Exit;	// Switches to the exit button
		}
		break;
	case button::Options: // The options button 

		// Sets the options button to be highlighted and the other buttons to be not
		m_buttons[0].loseFocus();
		m_buttons[1].getFocus();
		m_buttons[2].loseFocus();
		
		// Checks if the down button has been pressed
		if ((m_state.dpadDown && !m_controller.m_previousState.dpadDown) || (m_state.LeftThumbStick.y > 50 && m_controller.m_previousState.LeftThumbStick.y < 50))
		{
			m_buttonSelected = button::Exit;	// Switches to the exit button
		}
		
		// Checks if the up button has been pressed
		if ((m_state.dpadUp && !m_controller.m_previousState.dpadUp) || (m_state.LeftThumbStick.y < -50 && m_controller.m_previousState.LeftThumbStick.y > -50))
		{
			m_buttonSelected = button::Play;	// Switches to the play button
		}
		break;
	case button::Exit:	// The exit button

		// Sets the exit button to be highlighted and the other buttons to be not
		m_buttons[0].loseFocus();
		m_buttons[1].loseFocus();
		m_buttons[2].getFocus();
		
		// Checks if the down button has been pressed
		if ((m_state.dpadDown && !m_controller.m_previousState.dpadDown) || (m_state.LeftThumbStick.y > 50 && m_controller.m_previousState.LeftThumbStick.y < 50))
		{
			m_buttonSelected = button::Play;	// Switches to the play button
		}

		// Checks if the up button has been pressed
		if ((m_state.dpadUp && !m_controller.m_previousState.dpadUp) || (m_state.LeftThumbStick.y < -50 && m_controller.m_previousState.LeftThumbStick.y > -50))
		{
			m_buttonSelected = button::Options;	// Switches to the options button
		}
		break;
	default:
		break;
	}
}

// Function to check if the selected button has been pressed
void MainMenu::selectedButton(GamePadState m_state, Xbox360Controller2 m_controller)
{
	switch (m_buttonSelected) // Switch statement for the buttons
	{
	case Play:	// The play button 
		if (m_state.A && !m_controller.m_previousState.A)	// If the A button has been pressed
		{
			m_game->m_screen = MenuState::GameScreen;	// Sets the game screen to be the game
		}
		break;
	case Options:	// The options button 
		if (m_state.A && !m_controller.m_previousState.A && !m_transitionFromOptions)	// If the A button has been pressed
		{
			m_transitionToOptions = true;	// Sets the menu to transition to options
		}
		break;
	case Exit:	// The exit button 
		if (m_state.A && !m_controller.m_previousState.A)	// If the A button has been pressed
		{
			exit(0);	// Exits the game
		}
		break;
	default:
		break;
	}

}