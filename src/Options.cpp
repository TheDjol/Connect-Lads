#include "..\include\Options.h"


// Constructor for the options screen
OptionsScreen::OptionsScreen(Game& game, sf::Font &font) :
	m_game(&game),
	m_font(font)
{
	// Check to make sure the image loads correctly
	if (!m_backgroundTexture.loadFromFile(".\\resources\\images\\startBG.jpg"))
	{
		{
			std::string s("Error loading texture");	// Outputs error message
			throw std::exception(s.c_str());
		}

	}
	// Check to make sure the image loads correctly
	if (!m_buttonTex.loadFromFile(".\\resources\\images\\Button.png"))
	{
		{
			std::string s("Error loading texture");	// Outputs error message
			throw std::exception(s.c_str());
		}
	}
	// Check to make sure the image loads correctly
	if (!m_emptyRadioButtonTex.loadFromFile(".\\resources\\images\\emptyRadioButton.png"))
	{
		{
			std::string s("Error loading texture");	// Outputs error message
			throw std::exception(s.c_str());
		}
	}
	// Check to make sure the image loads correctly
	if (!m_fullRadioButtonTex.loadFromFile(".\\resources\\images\\radioButton.png"))
	{
		{
			std::string s("Error loading texture");	// Outputs error message
			throw std::exception(s.c_str());
		}
	}

	std::string back = "BACK";
	
	m_buttons = Button(&m_buttonTex, &back, &sf::Vector2f(1000, 400), &font);

	//Assigns the background texture to the background sprite
	m_backgroundSprite.setTexture(m_backgroundTexture);

	m_backgroundSprite.setOrigin(450, 300);	//Sets the backgrounds origin
	m_backgroundSprite.setPosition(450, 300);	//Sets the backgrounds position
	m_backgroundSprite.setScale(1.04, 1.04);	//Sets the backgrounds scale

	m_radioButton = RadioButton(&m_emptyRadioButtonTex, &sf::Vector2f(1000, 200));


	m_labelText = "Label";
	m_label = Label(&m_labelText, &m_font, &sf::Vector2f(800,200));

	m_slider = Slider(&sf::Vector2f(930, 280));

}

//Destructor function for the options screen
OptionsScreen::~OptionsScreen()
{
}

//Function to update the options screen
void OptionsScreen::update(GamePadState m_state, sf::Time deltaTime, Xbox360Controller2 m_controller)
{
	checkButtonSelected(m_state, m_controller);	//Calls the function to check which button is selected
	selectedButton(m_state, m_controller);	//Calls the function to check if a button has been clicked

	//If the options is transitioning in from the menu
	if (m_transitionFromMenu)
	{
		if (m_buttons.m_sprite.getPosition().x > 410)
		{
			
			m_buttons.moveLeft();
			m_radioButton.moveLeft();
			m_slider.moveLeft();
			m_label.moveLeft();
		}
		else
			m_transitionFromMenu = false;
		
	}

	m_slider.update();

	//If the options is transitioning to the menu
	if (m_transitionToMenu)
	{
		if ((m_buttons.m_sprite.getPosition().x  <= 1000))
		{
			m_buttons.moveRight();
			m_radioButton.moveRight();
			m_slider.moveRight();
			m_label.moveRight();

		}
		else
		{
			m_transitionToMenu = false;
			m_transitionFromMenu = true;
			m_game->m_screen = MenuState::MenuScreen;
		}
	}

}

// Function to render the options screen
void OptionsScreen::render(sf::RenderWindow & window)
{
	window.clear(sf::Color(220, 20, 60));	// Clears the screen with a nice red colour

	window.draw(m_backgroundSprite);		// Draws the background
	m_radioButton.render(window);
	m_buttons.render(window);
	m_slider.render(window);
	m_label.render(window);

	window.display();	// Displays the screen
}

// Function to edit the text based on if theyre selected
// And to check if the player is moving between buttons
void OptionsScreen::checkButtonSelected(GamePadState m_state, Xbox360Controller2 m_controller)
{
	// Switch statement to check which button is selected
	switch (m_oButton)
	{
	case Option1:
		m_buttons.loseFocus();
		m_slider.loseFocus();
		m_radioButton.getFocus();
		m_label.getFocus();
		// Checks if the player is trying to select the button below the current one
		if ((m_state.dpadDown && !m_controller.m_previousState.dpadDown) || (m_state.LeftThumbStick.y > 50 && m_controller.m_previousState.LeftThumbStick.y < 50))
		{
			m_oButton = optionButton::Option2;	// Changes the current button
		}

		// Checks if the player is trying to select the button above the current one
		if ((m_state.dpadUp && !m_controller.m_previousState.dpadUp) || (m_state.LeftThumbStick.y < -50 && m_controller.m_previousState.LeftThumbStick.y > -50))
		{
			m_oButton = optionButton::Option3;	// Changes the current button
		}
		break;
	case Option2:
		m_buttons.loseFocus();
		m_slider.getFocus();
		m_radioButton.loseFocus();
		m_label.loseFocus();
		// Checks if the player is trying to select the button below the current one
		if ((m_state.dpadDown && !m_controller.m_previousState.dpadDown) || (m_state.LeftThumbStick.y > 50 && m_controller.m_previousState.LeftThumbStick.y < 50))
		{
			m_oButton = optionButton::Option3;	// Changes the current button
		}

		// Checks if the player is trying to select the button above the current one
		if ((m_state.dpadUp && !m_controller.m_previousState.dpadUp) || (m_state.LeftThumbStick.y < -50 && m_controller.m_previousState.LeftThumbStick.y > -50))
		{
			m_oButton = optionButton::Option1;	// Changes the current button
		}

		
		if (m_state.dpadLeft || m_state.LeftThumbStick.x < -50)
		{
			m_slider.decrementSlider();
		}

		
		if (m_state.dpadRight  || m_state.LeftThumbStick.x > 50)
		{
			m_slider.incrementSlider();
		}

		break;
	case Option3:
		m_buttons.getFocus();
		m_slider.loseFocus();
		m_radioButton.loseFocus();
		m_label.loseFocus();
		// Checks if the player is trying to select the button below the current one
		if ((m_state.dpadDown && !m_controller.m_previousState.dpadDown) || (m_state.LeftThumbStick.y > 50 && m_controller.m_previousState.LeftThumbStick.y < 50))
		{
			m_oButton = optionButton::Option1;	// Changes the current button
		}

		// Checks if the player is trying to select the button above the current one
		if ((m_state.dpadUp && !m_controller.m_previousState.dpadUp) || (m_state.LeftThumbStick.y < -50 && m_controller.m_previousState.LeftThumbStick.y > -50))
		{
			m_oButton = optionButton::Option2;	// Changes the current button
		}
		break;
	default:
		break;
	}
}

//Function to check if buttons are selected 
void OptionsScreen::selectedButton(GamePadState m_state, Xbox360Controller2 m_controller)
{
	//Switch statement for which button has been picked
	switch (m_oButton)
	{
	case Option1:
		if (m_state.A && !m_controller.m_previousState.A)	// Checks if the A button has been pressed
		{
			if (!m_radioButton.m_filled)
			{
				m_radioButton.m_sprite.setTexture(m_fullRadioButtonTex);
				m_radioButton.m_filled = true;;
			}
			else
			{
				m_radioButton.m_sprite.setTexture(m_emptyRadioButtonTex);
				m_radioButton.m_filled = false;
			}
			
		}
		break;
	case Option2:
		break;
	case Option3:
		if (m_state.A && !m_controller.m_previousState.A && !m_transitionFromMenu)	// Checks if the A button has been pressed
		{
			m_transitionToMenu = true;	// Starts the transition to the menu
		}
		break;
	default:
		break;
	}
}