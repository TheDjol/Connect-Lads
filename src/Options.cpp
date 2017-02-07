#include "..\include\Options.h"


//Constructor for the options screen
OptionsScreen::OptionsScreen(Game& game, sf::Font &font) :
	m_game(&game)
{
	//check to make sure the image loads correctly
	if (!m_backgroundTexture.loadFromFile(".\\resources\\images\\startBG.jpg"))
	{
		{
			std::string s("Error loading texture");	//Outputs error message
			throw std::exception(s.c_str());
		}

	}
	//check to make sure the image loads correctly
	if (!m_buttonTex.loadFromFile(".\\resources\\images\\Button.png"))
	{
		{
			std::string s("Error loading texture");	//Outputs error message
			throw std::exception(s.c_str());
		}
	}

	std::string yeah = "MEME";
	std::string back = "BACK";

	m_buttons[0] = Button(&m_buttonTex, &yeah, &sf::Vector2f(450, 200), &font);
	m_buttons[1] = Button(&m_buttonTex, &back, &sf::Vector2f(450, 300), &font);

	//Assigns the background texture to the background sprite
	m_backgroundSprite.setTexture(m_backgroundTexture);

	m_backgroundSprite.setOrigin(450, 300);	//Sets the backgrounds origin
	m_backgroundSprite.setPosition(450, 300);	//Sets the backgrounds position
	m_backgroundSprite.setScale(1.04, 1.04);	//Sets the backgrounds scale

	m_slider.setFillColor(sf::Color(0, 0, 0));	//Sets the initial slider colour to black
	m_slider.setPosition(1000, 300);	//Sets the sliders position
	m_slider.setSize(sf::Vector2f(180, 30));	//Sets the size fo the slider

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
		
	}

	//If the options is transitioning to the menu
	if (m_transitionToMenu)
	{

	}
}

//Function to render the options screen
void OptionsScreen::render(sf::RenderWindow & window)
{
	window.clear(sf::Color(220, 20, 60));	//Clears the screen with a nice red colour

	window.draw(m_backgroundSprite);		//Draws text to the screen

	window.draw(m_slider);	//draws the slider

	window.display();	//Displays the screen
}

//Function to edit the text based on if theyre selected
//And to check if the player is moving between buttons
void OptionsScreen::checkButtonSelected(GamePadState m_state, Xbox360Controller2 m_controller)
{
	//Switch statement to check which button is selected
	switch (m_oButton)
	{
	case Option1:
		m_slider.setFillColor(sf::Color(0, 0, 0));

		//Checks if the player is trying to select the button below the current one
		if ((m_state.dpadDown && !m_controller.m_previousState.dpadDown) || (m_state.LeftThumbStick.y > 50 && m_controller.m_previousState.LeftThumbStick.y < 50))
		{
			m_oButton = optionButton::Option2;	//Changes the current button
		}

		//Checks if the player is trying to select the button above the current one
		if ((m_state.dpadUp && !m_controller.m_previousState.dpadUp) || (m_state.LeftThumbStick.y < -50 && m_controller.m_previousState.LeftThumbStick.y > -50))
		{
			m_oButton = optionButton::Option3;	//Changes the current button
		}
		break;
	case Option2:
		m_slider.setFillColor(sf::Color(236, 0, 24));

		//Checks if the player is trying to select the button below the current one
		if ((m_state.dpadDown && !m_controller.m_previousState.dpadDown) || (m_state.LeftThumbStick.y > 50 && m_controller.m_previousState.LeftThumbStick.y < 50))
		{
			m_oButton = optionButton::Option3;	//Changes the current button
		}

		//Checks if the player is trying to select the button above the current one
		if ((m_state.dpadUp && !m_controller.m_previousState.dpadUp) || (m_state.LeftThumbStick.y < -50 && m_controller.m_previousState.LeftThumbStick.y > -50))
		{
			m_oButton = optionButton::Option1;	//Changes the current button
		}
		break;
	case Option3:
		m_slider.setFillColor(sf::Color(0, 0, 0));

		//Checks if the player is trying to select the button below the current one
		if ((m_state.dpadDown && !m_controller.m_previousState.dpadDown) || (m_state.LeftThumbStick.y > 50 && m_controller.m_previousState.LeftThumbStick.y < 50))
		{
			m_oButton = optionButton::Option1;	//Changes the current button
		}

		//Checks if the player is trying to select the button above the current one
		if ((m_state.dpadUp && !m_controller.m_previousState.dpadUp) || (m_state.LeftThumbStick.y < -50 && m_controller.m_previousState.LeftThumbStick.y > -50))
		{
			m_oButton = optionButton::Option2;	//Changes the current button
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
		break;
	case Option2:
		break;
	case Option3:
		if (m_state.A && !m_controller.m_previousState.A)	//Checks if the back button has been pressed
		{
			m_transitionToMenu = true;	//Starts the transition to the menu
		}
		break;
	default:
		break;
	}
}