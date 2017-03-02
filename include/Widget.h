#ifndef WIDGET_H
#define WIDGET_H

#include "Xbox360Controller.h"
#include <iostream>

class Widget
{
public:
	Widget();	// Constructor for the widget object.
	~Widget();	// Deconstructor for the widget object.
	
	/// <summary>
	/// Update method that will be passed to all classes that inherit the widget class,
	/// This must be overwritten as it is pure virtual.
	/// </summary>
	virtual void update() = 0;

	/// <summary>
	/// Render method that will be passed to all classes that inherit the widget class,
	/// This must be overwritten as it is pure virtual.
	/// Takes the address of the game window as a argument.
	/// </summary>
	/// <param name="window"></param>
	virtual void render(sf::RenderWindow& window) = 0;

	/// <summary>
	/// This method sets the hasFocus bool to "True",
	/// While also giving the player a indication of what button they are on. 
	/// This Method doesn't have to be overwritten but it can be.
	/// </summary>
	virtual void getFocus();

	/// <summary>
	/// This method sets the hasFocus bool to "False",
	/// While also giving the player a indication of what button they are on. 
	/// This Method doesn't have to be overwritten but it can be.
	/// </summary>
	virtual void loseFocus();

private:
	bool hasFocus;	// Bool used to determine whether or not the widget has focus.
};

#endif // !WIDGET_H

#ifndef BUTTON_H
#define BUTTON_H

class Button : public Widget
{
public:
	Button();	// Default constructor for the Button object.
	/// <summary>
	/// Overloaded constructor for the Button object.
	/// Takes a texture used to represent the button, a string of text, 
	/// a Vector of two floats for the positon of the button and a font that is used to write the text as its arguments.
	/// </summary>
	/// <param name="texture"></param>
	/// <param name="text"></param>
	/// <param name="position"></param>
	/// <param name="font"></param>
	Button(sf::Texture& texture, std::string *text, sf::Vector2f *position, sf::Font *font);
	~Button();	// Deconstructor for the Button object.

	virtual void update() override;	// "update" method for the Button object, Overrides the "update" method in the widget.
	/// <summary>
	/// "render" method for the Button object, Overrides the "render" method in the widget.
	/// Takes the address of the game window as a argument.
	/// </summary>
	/// <param name="window"></param>
	virtual void render(sf::RenderWindow& window) override;

	/// <summary>
	/// "getFocus" method for the Button object, Overrides the "getFocus" method in the widget,
	/// As this method also changes the colour of the text on the button to show the player that the button "hasFocus".
	/// </summary>
	virtual void getFocus() override;

	/// <summary>
	/// "getFocus" method for the Button object, Overrides the "getFocus" method in the widget,
	/// As this method also changes the colour of the text on the button to show the player that "hasFocus" is false.
	/// </summary>
	virtual void loseFocus() override;

	void scaleButtons(float xScale, float yScale);	// Method that scales the buttons so that they can shrink and grow.

	void moveRight();	// Method to move the button right, This method is called in transitions.
	void moveLeft();	// Method to move the button left, This method is called in transitions.

	sf::Vector2f m_position;	// Stores the postion of the Button.
	sf::Sprite m_sprite;	// Is used to store and draw the Button texture.
	

private:
	
	sf::Texture m_texture;	// Stores the texture of the Button.
	
	sf::Text m_text;	// Stores the text that will be written on the Button.
	sf::Font m_font;	// Stores the font that will be used to draw the Text.
	bool m_hasFocus;	// Determines whether or not the Button hasFocus;
	sf::FloatRect m_textRectangle;	// Rectangle used to set the origin of the text to its centre, this is done to allow for the text to be centred easier.
	sf::FloatRect m_spriteRectangle;	// Rectangle used to set the origin of the sprite to its centre, this is done to allow the sprite to be centred easier.
};
#endif // !BUTTON_H

#ifndef RADIOBUTTON_H
#define RADIOBUTTON_H

class RadioButton : public Widget
{
public:
	RadioButton();	// Default constructor for the RadioButton object.
	/// <summary>
	/// Overloaded constructor for the RadioButton object.
	/// Takes a texture used to represent the RadioButton and a vector of two floats that is used to represent its on-screen position.
	/// </summary>
	/// <param name="texture"></param>
	/// <param name="position"></param>
	RadioButton(sf::Texture *texture, sf::Vector2f *position);
	~RadioButton();	// Deconstructor for the RadioButton object.

	virtual void update() override;	// "update" method for the RadioButton object, Overrides the "update" method in the widget.
	/// <summary>
	/// "render" method for the RadioButton object, Overrides the "render" method in the widget.
	/// Takes the address of the game window as a argument.
	/// </summary>
	/// <param name="window"></param>
	virtual void render(sf::RenderWindow& window) override;

	virtual void getFocus();	// Gives the RadioButton focus. Doesn't need to override the method in the widget class as they are the same.
	virtual void loseFocus();	// Takes focus from the RadioButton. Doesn't need to override the method in the widget class as they are the same.

	void moveRight();	// Moves the RadioButton to the right, This is used in screen transitions.
	void moveLeft();	// Moves the RadioButton to the left, This is used in screen transitions.

	sf::Vector2f m_position;	// Stores the postion of the RadioButton.
	sf::Sprite m_sprite;	// Uses the texture and positon to represent the RadioButton on the screen to the player.

	bool m_filled = false; // If the radio button is filled or not

private:
	sf::Texture m_texture;	// Stores the texture of the RadioButton.
	bool m_hasFocus;	// Used to determine whether or not the RadioButton hasFocus.
	sf::FloatRect m_spriteRectangle;	// Rectangle used to find the centre of the texture so that the sprite can be placed easier on screen.
};
#endif // !RADIOBUTTON_H

#ifndef SLIDER_H
#define SLIDER_H

class Slider : public Widget
{
public:
	Slider();	// Default constructor for the Slider object.
	/// <summary>
	/// Overloaded constructor for the Slider object.
	/// Takes a vector of two floats to represent the objects position 
	/// and an integer used to determine how many segments the slider is made up of as its arguments.
	/// </summary>
	/// <param name="position"></param>
	/// <param name="numOfSegments"></param>
	Slider(sf::Vector2f *position, int numOfSegments);
	~Slider();	// Deconstructor for the Slider object.

	virtual void update() override;	// "update" method for the Slider object, Overrides the "update" method in the widget.
	/// <summary>
	/// "render" method for the Slider object, Overrides the "render" method in the widget.
	/// Takes the address of the game window as a argument.
	/// </summary>
	/// <param name="window"></param>
	virtual void render(sf::RenderWindow& window) override;

	virtual void getFocus() override;	// Method that sets hasFocus to "True" as well as changing the colour of the Slider to show that it hasFocus.
	virtual void loseFocus() override;	// Method that sets hasFocus to "False" as well as changing the colour of the Slider to show it no longer hasFocus.

	void moveRight();	// Moves the Slider object to the right, This is called for transitioning between screens.
	void moveLeft();	// Moves the Slider object to the left, This is called for transitioning between screens.

	int incrementSlider();	// Increments the Slider by one segment.
	int decrementSlider();	// Decrements the Slider by one segment.

	sf::Vector2f m_position;	// Stores the positon of the Slider object.

	sf::RectangleShape m_slider;	// Used to represent the Slider on-screen.

private:
	bool m_hasFocus;	// Determines whether or not the Slider hasFocus.
	
	int m_numOfSegments;	// Stores the number of different segments the Slider is broken up into.
	int m_currentSegment;	// Stores the number of the segment the Slider is currently on.

	float m_circleSize;	// Stores the value of the size of m_circle.
	sf::Vector2f m_rectangleSize;	// Stores the value of the size of m_slider and m_sliderBackground.

	sf::CircleShape m_circle;	// Placed at the end of the Slider rectangle to give the player a easy point to follow.
	sf::RectangleShape m_sliderBackground;	// What the rest of the Slider sits upon to seperate it from the background image.
};
#endif // !SLIDER_H

#ifndef LABEL_H
#define LABEL_H

class Label :  public Widget
{
public:
	Label();	// Default constructor for the Label object.
	/// <summary>
	/// Overloaded constructor fothe Label object.
	/// Takes a string of text that is to drawn on screen, the font that the text will be, 
	/// the position the text will be on-screen and the size of the font as arguments.
	/// </summary>
	/// <param name="text"></param>
	/// <param name="font"></param>
	/// <param name="position"></param>
	/// <param name="size"></param>
	Label(std::string *text, sf::Font *font, sf::Vector2f *position, int size);
	~Label();	// Deconstructor for the Label object.

	virtual void update() override;	// "update" method for the Label object, Overrides the "update" method in the widget.
	/// <summary>
	/// "render" method for the Label object, Overrides the "render" method in the widget.
	/// Takes the address of the game window as a argument.
	/// </summary>
	/// <param name="window"></param>
	virtual void render(sf::RenderWindow& window) override;
	
	virtual void getFocus() override;	// Sets hasFocus to "True" as well as changes the colour of the text to show the player that the Label hasFocus.
	virtual void loseFocus() override;	// Sets hasFocus to "False" as well as changes the colour of the text to show the player that the label no longer hasFocus.

	void moveRight();	// Moves the Label right, This is used for transitioning between screens.
	void moveLeft();	// Moves the Label left, This is used for transitioning between screens.

	sf::Vector2f m_position;	// Stores the on-screen positon of the Label.

private:
	bool m_hasFocus;	// Determines whether or not the Label hasFocus.

	sf::Text m_text;	// Stores the string of text that is to be drawn on screen.
	sf::Font m_font;	// Stores the font that is used to draw the text.
	sf::FloatRect m_textRectangle;	// Rectangle used to find the centre of the text so that it can be placed easier on the screen.
};

#endif // !LABEL_H