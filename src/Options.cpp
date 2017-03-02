#include "Options.h"

OptionsScreen::OptionsScreen(Game& game, sf::Font &font, sf::RenderWindow &window) :
	m_game(&game),	// Sets m_game to the address of the game argument.
	m_font(font),	// Sets m_font to the address of the m_font argument.
	m_window(window)	// Sets m_window to the address of the window argument.
{
	if (!m_backgroundTexture.loadFromFile(".\\resources\\images\\startBG.jpg"))	// Check to make sure the image loads correctly.
	{
		{
			std::string s("Error loading texture");	// Outputs error message.
			throw std::exception(s.c_str());	// Opens a error window with the error message displayed.
		}

	}
	
	if (!m_buttonTex.loadFromFile(".\\resources\\images\\Button.png"))	// Check to make sure the image loads correctly.
	{
		{
			std::string s("Error loading texture");	// Outputs error message.
			throw std::exception(s.c_str());	// Opens a error window with the error message displayed.
		}
	}
	
	if (!m_emptyRadioButtonTex.loadFromFile(".\\resources\\images\\emptyRadioButton.png"))	// Check to make sure the image loads correctly.
	{
		{
			std::string s("Error loading texture");	// Outputs error message.
			throw std::exception(s.c_str());	// Opens a error window with the error message displayed.
		}
	}
	
	if (!m_fullRadioButtonTex.loadFromFile(".\\resources\\images\\radioButton.png"))	// Check to make sure the image loads correctly.
	{
		{
			std::string s("Error loading texture");	// Outputs error message.
			throw std::exception(s.c_str());	// Opens a error window with the error message displayed.
		}
	}

	std::string back = "BACK";	// Creates a string called and assigns it a value.
	m_buttons = Button(m_buttonTex, &back, &sf::Vector2f(1000, 400), &font);	// Initalizes the button.

	m_backgroundSprite.setTexture(m_backgroundTexture);	// Assigns the background texture to the background sprite.
	m_backgroundSprite.setOrigin(450, 300);	// Sets the backgrounds origin.
	m_backgroundSprite.setPosition(450, 300);	// Sets the backgrounds position.
	m_backgroundSprite.setScale(1.04, 1.04);	// Sets the backgrounds scale.

	m_radioButton = RadioButton(&m_emptyRadioButtonTex, &sf::Vector2f(950, 200));	// Initalizes the radioButton.

	m_labelText[0] = "Mute";
	m_label[0] = Label(&m_labelText[0], &m_font, &sf::Vector2f(1020,200), 38);	// Initalizes the label.

	m_labelText[1] = "Window Size";
	m_label[1] = Label(&m_labelText[1], &m_font, &sf::Vector2f(1010, 270), 28);	// Initalizes the label.

	m_slider = Slider(&sf::Vector2f(930, 300), 5);	// Initalizes the slider.
	m_sliderValue = 5;	// Number of segments in the slider.

}

OptionsScreen::~OptionsScreen()	
{
}

void OptionsScreen::update(GamePadState m_state, sf::Time deltaTime, Xbox360Controller2 m_controller)
{
	checkButtonSelected(m_state, m_controller);	// Calls the function to check which button is selected.
	selectedButton(m_state, m_controller);	// Calls the function to check if a button has been clicked.
	changeWindowResolution(m_window);	// Calls the changeWindowResolution method.
	m_slider.update();	// Calls the update method in the slider class.
	
	if (!m_radioButton.m_filled && m_previouslyFilled)	// If the radioButton is empty and was filled on the last update then this is true.
	{
		m_game->pauseMusic(false);	// UnPauses the music.
	}
	else if (m_radioButton.m_filled && !m_previouslyFilled)	// If the radioButton is full and was empty on the last update then this is true.
	{
		m_game->pauseMusic(true);	// Pauses the music.
	}
	

	
	if (m_transitionFromMenu)	// If the options is transitioning in from the menu.
	{
		if (m_buttons.m_sprite.getPosition().x > 410)	// If the ui is not in position and the player has come from the menu this is true.
		{
			m_buttons.moveLeft();	// Calls the moveLeft method in the button class.
			m_radioButton.moveLeft();	// Calls the moveLeft method in the radio button class.
			m_slider.moveLeft();	// Calls the moveLeft method in the slider class.
			m_label[0].moveLeft();	// Calls the moveLeft method in the label class.
			m_label[1].moveLeft();
		}
		else
		{
			m_transitionFromMenu = false;	// Sets bool to false.
		}
	}

	
	if (m_transitionToMenu)	// If the options is transitioning to the menu.
	{
		if ((m_buttons.m_sprite.getPosition().x  <= 1000))	// If the ui was in position and the player is going to the menu this is true.
		{
			m_buttons.moveRight();	// Calls the moveRight method in the button class.
			m_radioButton.moveRight();	// Calls the moveRight method in the radio button class.
			m_slider.moveRight();	// Calls the moveRight method in the slider class.
			m_label[0].moveRight();	// Calls the moveRight method in the label class.
			m_label[1].moveRight();
		}
		else
		{
			m_transitionToMenu = false;	// Sets bool to false.
			m_transitionFromMenu = true;	// Resets bool so that it can transition back in.
			m_game->m_screen = MenuState::MenuScreen;	// Changes game state to be the menu screen.
		}
	}

	m_previouslyFilled = m_radioButton.m_filled;	// Sets previously filled to the value in m_filled.
}

void OptionsScreen::render(sf::RenderWindow & window)	// Function to render the options screen.
{
	window.clear(sf::Color(220, 20, 60));	// Clears the screen with a nice red colour.

	window.draw(m_backgroundSprite);	// Draws the background.
	m_radioButton.render(window);	// Draws the radio button.
	m_buttons.render(window);	// Draws the button.
	m_slider.render(window);	// Draws the slider.
	m_label[0].render(window);	// Draws the label.
	m_label[1].render(window);	// Draws the label.

	window.display();	// Displays the screen.
}

/// <summary>
/// Function to edit the text based on if theyre selected
/// And to check if the player is moving between buttons.
/// </summary>
/// <param name="m_state"></param>
/// <param name="m_controller"></param>
void OptionsScreen::checkButtonSelected(GamePadState m_state, Xbox360Controller2 m_controller)
{
	switch (m_oButton)	// Switch statement to check which button is selected
	{
	case Option1:

		m_buttons.loseFocus();	// Removes focus.
		m_slider.loseFocus();	// Removes focus.
		m_radioButton.getFocus();	// Gives focus.
		m_label[0].getFocus();	// Gives focus.
		m_label[1].loseFocus(); // Removes focus
		
		if ((m_state.dpadDown && !m_controller.m_previousState.dpadDown) || (m_state.LeftThumbStick.y > 50 && m_controller.m_previousState.LeftThumbStick.y < 50))	// Checks if the player is trying to select the button below the current one.
		{
			m_oButton = optionButton::Option2;	// Changes the current button.
		}

		
		if ((m_state.dpadUp && !m_controller.m_previousState.dpadUp) || (m_state.LeftThumbStick.y < -50 && m_controller.m_previousState.LeftThumbStick.y > -50))	// Checks if the player is trying to select the button above the current one.
		{
			m_oButton = optionButton::Option3;	// Changes the current button.
		}
		break;

	case Option2:

		m_buttons.loseFocus();	// Removes focus.
		m_slider.getFocus();	// Gives focus.
		m_radioButton.loseFocus();	// Removes focus.
		m_label[0].loseFocus();	// Removes focus.
		m_label[1].getFocus();	// Get focus.
		
		if ((m_state.dpadDown && !m_controller.m_previousState.dpadDown) || (m_state.LeftThumbStick.y > 50 && m_controller.m_previousState.LeftThumbStick.y < 50))	// Checks if the player is trying to select the button below the current one.
		{
			m_oButton = optionButton::Option3;	// Changes the current button.
		}

		
		if ((m_state.dpadUp && !m_controller.m_previousState.dpadUp) || (m_state.LeftThumbStick.y < -50 && m_controller.m_previousState.LeftThumbStick.y > -50))	// Checks if the player is trying to select the button above the current one.
		{
			m_oButton = optionButton::Option1;	// Changes the current button.
		}

		
		if ((m_state.dpadLeft && !m_controller.m_previousState.dpadLeft) || (m_state.LeftThumbStick.x < -50 && m_controller.m_previousState.LeftThumbStick.x > -50))	// Decrements the slider if the player pushes the d-pad or thumbstick left.
		{
			m_sliderValue = m_slider.decrementSlider();
		}

		
		if ((m_state.dpadRight && !m_controller.m_previousState.dpadRight) || (m_state.LeftThumbStick.x > 50 && m_controller.m_previousState.LeftThumbStick.x < 50))	// Increments the slider if the player pushes the d - pad or thumbstick left.
		{
			m_sliderValue = m_slider.incrementSlider();
		}

		break;

	case Option3:

		m_buttons.getFocus();	// Gives focus.
		m_slider.loseFocus();	// Removes focus.
		m_radioButton.loseFocus();	// Removes focus.
		m_label[0].loseFocus();	// Removes focus.
		m_label[1].loseFocus();
		
		if ((m_state.dpadDown && !m_controller.m_previousState.dpadDown) || (m_state.LeftThumbStick.y > 50 && m_controller.m_previousState.LeftThumbStick.y < 50))	// Checks if the player is trying to select the button below the current one.
		{
			m_oButton = optionButton::Option1;	// Changes the current button.
		}

		
		if ((m_state.dpadUp && !m_controller.m_previousState.dpadUp) || (m_state.LeftThumbStick.y < -50 && m_controller.m_previousState.LeftThumbStick.y > -50))	// Checks if the player is trying to select the button above the current one.
		{
			m_oButton = optionButton::Option2;	// Changes the current button
		}
		break;

	default:
		break;
	}
}

void OptionsScreen::selectedButton(GamePadState m_state, Xbox360Controller2 m_controller)	// Function to check if buttons are selected. 
{
	
	switch (m_oButton)	// Switch statement for which button has been picked.
	{
	case Option1:
		if (m_state.A && !m_controller.m_previousState.A)	// Checks if the A button has been pressed
		{
			if (!m_radioButton.m_filled)	// Checks if the radio button is filled.
			{
				m_radioButton.m_sprite.setTexture(m_fullRadioButtonTex);	// Assigns the full button texture to the button.
				m_radioButton.m_filled = true;	// Sets the bool to true to represent that the radio button is filled.
			}
			else
			{
				m_radioButton.m_sprite.setTexture(m_emptyRadioButtonTex);	// Assigns the empty button texture to the button.
				m_radioButton.m_filled = false;	// Sets the bool to false to represent that the radio button is empty.
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

void OptionsScreen::changeWindowResolution(sf::RenderWindow & window)	// Method that changes the window resolution depending on the value of the slider.
{
	if (m_sliderValue == 0)	// Checks the value of the slider.
	{
		window.setSize(sf::Vector2u(360,240));	// Sets the size of the game window.
	}
	else if (m_sliderValue == 1)	// Checks the value of the slider.
	{
		window.setSize(sf::Vector2u(450,300));	// Sets the size of the game window.
	}
	else if (m_sliderValue == 2)	// Checks the value of the slider.
	{
		window.setSize(sf::Vector2u(600, 400));	// Sets the size of the game window.
	}
	else if (m_sliderValue == 3)	// Checks the value of the slider.
	{
		window.setSize(sf::Vector2u(750,500));	// Sets the size of the game window.
	}
	else if (m_sliderValue == 4)	// Checks the value of the slider.
	{
		window.setSize(sf::Vector2u(900, 600));	// Sets the size of the game window.
	}
}
