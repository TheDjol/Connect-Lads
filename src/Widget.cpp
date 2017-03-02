#include "Widget.h"
#pragma region WidgetRegion

Widget::Widget()
{
}

Widget::~Widget()
{
}

void Widget::update()
{
}

void Widget::render(sf::RenderWindow & window)
{
}

void Widget::getFocus()
{
	hasFocus = true;
}

void Widget::loseFocus()
{
	hasFocus = false;
}

#pragma endregion

#pragma region ButtonRegion

Button::Button()
{

}

Button::Button(sf::Texture& texture, std::string *text, sf::Vector2f *position, sf::Font *font) :
	m_texture(texture),	// Sets m_texture to the address of the texture argument.
	m_position(*position),	// Sets m_position to the de-referenced value of the position argument.
	m_text(*text, *font, 28)	// Sets m_text to the de-referenced value of the text argument as well as the de-referenced value of the font argument and then sets the size of the text to 28.
{
	m_sprite.setTexture(texture);	// Sets the texture of the sprite to be that of the texture stored at the address.

	m_spriteRectangle = m_sprite.getLocalBounds();	// Gets the dimensions of the rectangle that contains the sprite.
	m_sprite.setOrigin(m_spriteRectangle.left + m_spriteRectangle.width / 2.0f, m_spriteRectangle.top + m_spriteRectangle.height / 2.0f);	// Centres the origin of the text.
	m_sprite.setPosition(m_position);	// Sets the position of the sprite with its centre now being its origin.

	m_textRectangle = m_text.getLocalBounds();	// Gets the dimensions of the rectangle that contains the text.
	m_text.setOrigin(m_textRectangle.left + m_textRectangle.width / 2.0f, m_textRectangle.top + m_textRectangle.height / 2.0f);	// Centres the origin of the text.
	m_text.setPosition(m_position);	// Sets the position of the text with its centre now being its origin.
	m_text.setColor(sf::Color(0, 0, 0));	// Sets the colour of the text to black.
}

Button::~Button()
{	
}

void Button::update()
{
}

void Button::getFocus()
{
	m_text.setColor(sf::Color(236, 0, 24));	// Sets the colour of the text to red.
	m_hasFocus = true;	// Sets the variable m_hasFocus to true.
}

void Button::loseFocus()
{
	m_text.setColor(sf::Color(0,0,0));	// Sets the colour of the text to black.
	m_hasFocus = false;	// Sets the variable m_hasFocus to false.
}

void Button::scaleButtons(float xScale, float yScale)
{
	m_sprite.setScale(xScale, yScale);	// Scales the button by the arguments given.
}

void Button::moveRight()
{
	m_sprite.setPosition(m_sprite.getPosition().x + 1, m_sprite.getPosition().y);	// Moves the sprite by positive one along the x-axis each time this is called, the y-axis remains the same. 
	m_text.setPosition(m_text.getPosition().x + 1, m_text.getPosition().y);	// Moves the text by positive one along the x-axis each time this is called, the y-axis remains the same.
}

void Button::moveLeft()
{
	m_sprite.setPosition(m_sprite.getPosition().x - 1, m_sprite.getPosition().y);	// Moves the sprite by negative one along the x-axis each time this is called, the y-axis remains the same.
	m_text.setPosition(m_text.getPosition().x - 1, m_text.getPosition().y);	// Moves the text by negative one along the x-axis each time this is called, the y-axis remains the same.
}


void Button::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);	// Draws the sprite to the screen.
	window.draw(m_text);	// Draws the text on top of the sprite.
}

#pragma endregion

#pragma region RadioButtonRegion

RadioButton::RadioButton()
{
}

RadioButton::RadioButton(sf::Texture * texture, sf::Vector2f * position) :
	m_position(*position),	// Sets m_position to the de-referenced value of the position argument.
	m_texture(*texture)	// Sets m_texture to the de-referenced value of the texture argument.
{

	m_sprite.setTexture(*texture);	// Sets the texture of the sprite to be that of the de-referenced texture.

	m_spriteRectangle = m_sprite.getLocalBounds();	// Gets the dimensions of the rectangle that contains the text.
	m_sprite.setOrigin(m_spriteRectangle.left + m_spriteRectangle.width / 2.0f, m_spriteRectangle.top + m_spriteRectangle.height / 2.0f);	// Centres the origin of the text.
	m_sprite.setPosition(m_position);	// Sets the position of the sprite to m_position with its centre as its origin.
}

RadioButton::~RadioButton()
{
}

void RadioButton::update()
{
}

void RadioButton::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);	// Draws the sprite to the screen.
}

void RadioButton::getFocus()
{
	m_hasFocus = true;	// Gives focus to the RadioButton.
}

void RadioButton::loseFocus()
{
	m_hasFocus = false;	// Takes focus from the RadioButton.
}

void RadioButton::moveRight()
{
	m_sprite.setPosition(m_sprite.getPosition().x + 1, m_sprite.getPosition().y);	// Moves the sprite by positive one along the x-axis, while leaving the y-axis the same.
}

void RadioButton::moveLeft()
{
	m_sprite.setPosition(m_sprite.getPosition().x - 1, m_sprite.getPosition().y);	// Moves the sprite by negative one along the x-axis, while leaving the y-axis the same.
}

#pragma endregion

#pragma region SliderRegion


Slider::Slider()
{

}

Slider::Slider(sf::Vector2f * position, int numOfSegments) :
	m_position(*position),	// Sets m_position to the de-referenced value of position.
	m_numOfSegments(numOfSegments - 1)	// One is taken from numOfSegments to allow for using zero based numbering.
{
	m_circleSize = 15.0f;	// Value of the size of m_circle.
	m_rectangleSize = sf::Vector2f(150.0f, 20.0f);	// Values used in both rectangle slider components.

	m_sliderBackground.setPosition(m_position);	// Sets the position of the slider background using the top left corner as the origin.
	m_slider.setPosition(m_position);	// Sets the position of the slider using the top left corner as the origin.
	m_circle.setPosition(m_position);	// Sets the position of the slider's circle using it's centre as the origin.

	m_sliderBackground.setFillColor(sf::Color::Blue);	// Sets the colour of the slider background to blue.
	m_slider.setFillColor(sf::Color(0,0,0));	// Sets the colour of the slider to black.
	m_circle.setFillColor(sf::Color(0,0,0));	// Sets the colour of the slider's circle to black.

	m_sliderBackground.setSize(m_rectangleSize);	// Sets the size of the slider background to the values in m_rectangleSize.
	m_slider.setSize(m_rectangleSize);	// Sets the size of the slider background to the values in m_rectangleSize.
	m_circle.setRadius(m_circleSize);	// Sets the size of the circle to the value in m_circleSize.

	m_currentSegment = m_numOfSegments;	// sets m_currentSegment to the maximum possible value.
}

Slider::~Slider()
{
}

void Slider::update()
{
	m_circle.setPosition(m_slider.getPosition().x + m_slider.getLocalBounds().width - (m_circle.getLocalBounds().width / 2), m_slider.getPosition().y - (m_circle.getLocalBounds().height / 6));	// Moves the circle to the end of the slider rectangle.
}

void Slider::render(sf::RenderWindow & window)
{
	window.draw(m_sliderBackground);	// Draws the slider background on the screen.
	window.draw(m_slider);	// Draws the slider on top of the slider background.
	window.draw(m_circle);	// Draws the circle on top of the end of the slider.
}

void Slider::getFocus()
{
	m_slider.setFillColor(sf::Color(236, 0, 24));	// Sets the colour of the slider to red.
	m_hasFocus = true;	// Gives the slider focus.
}

void Slider::loseFocus()
{
	m_slider.setFillColor(sf::Color(0, 0, 0));	// Sets the colour of the slider to black.
	m_hasFocus = false;	// takes focus from the slider
}

void Slider::moveRight()
{
	m_sliderBackground.setPosition(m_slider.getPosition().x + 1, m_slider.getPosition().y);	// Moves the slider background by positive one along the x-axis, the y-axis remains unchanged.
	m_slider.setPosition(m_slider.getPosition().x + 1, m_slider.getPosition().y);	// Moves the slider by positive one along the x-axis, the y-axis remains unchanged.
	m_circle.setPosition(m_circle.getPosition().x + 1, m_circle.getPosition().y);	// Moves the circle by positive one along the x-axis, the y-axis remains unchanged.
}

void Slider::moveLeft()
{
	m_sliderBackground.setPosition(m_sliderBackground.getPosition().x - 1, m_sliderBackground.getPosition().y);// Moves the slider background by positive one along the x-axis, the y-axis remains unchanged.
	m_slider.setPosition(m_slider.getPosition().x - 1, m_slider.getPosition().y);	// Moves the slider by positive one along the x - axis, the y - axis remains unchanged.
	m_circle.setPosition(m_circle.getPosition().x - 1, m_circle.getPosition().y);	// Moves the circle by positive one along the x - axis, the y - axis remains unchanged.
}

int Slider::incrementSlider()
{
	if (m_currentSegment < m_numOfSegments)	// Checks that m_currentSegment is less the value stored in m_numOfSegments.
	{
		m_currentSegment++;	// Increments the value in m_currentSegment.
		m_slider.setSize(sf::Vector2f((m_sliderBackground.getSize().x / m_numOfSegments) * m_currentSegment, m_slider.getSize().y));	// Sets the length of the slider to be that of the total maximum length divided by the total number of segments multiplied by the number of the current segment.
		m_circle.setPosition(m_slider.getPosition().x + m_slider.getLocalBounds().width, m_slider.getPosition().y);	// Sets the circles position to be at the end of the slider rectangle.
	}

	return m_currentSegment;	// Returns the current segment.
}

int Slider::decrementSlider()
{
	if (m_currentSegment > 0)	// Checks that m_currentSegment is greater that 0.
	{
		m_currentSegment--;	// Decrements the value in m_currentSegment.
		m_slider.setSize(sf::Vector2f((m_sliderBackground.getSize().x / m_numOfSegments) * m_currentSegment, m_slider.getSize().y));	// Sets the length of the slider to be that of the total maximum length divided by the total number of segments multiplied by the number of the current segment.
		m_circle.setPosition(m_slider.getPosition().x + m_slider.getLocalBounds().width, m_slider.getPosition().y);	// Sets the circles position to be at the end of the slider rectangle.
	}

	return m_currentSegment;	// Returns the current segment.
}

#pragma endregion

#pragma region LabelRegion

Label::Label()
{
}

Label::Label(std::string * text, sf::Font * font, sf::Vector2f *position, int size) :
	m_font(*font),	// Sets the value of m_font to that of the de-referenced value stored in the font argument.
	m_position(*position),	// Sets the value of m_position to that of the de-referenced value stored in the position argument.
	m_text(*text, *font, size)	// Sets m_text to use the de-referenced value in the text argument as the string, the de-referenced value in the font argument as the font and uses the text size of 38. 
{
	m_textRectangle = m_text.getLocalBounds();	// Gets the dimensions of the rectangle that contains the text.
	m_text.setOrigin(m_textRectangle.left + m_textRectangle.width / 2.0f, m_textRectangle.top + m_textRectangle.height / 2.0f);	// Centres the origin of the text.
	m_text.setPosition(m_position);	// Sets the position of the text using its centre as the origin.
	m_text.setColor(sf::Color(0, 0, 0));	// Sets the colour of the text to black.
}

Label::~Label()
{

}

void Label::update()
{
}

void Label::render(sf::RenderWindow & window)
{
	window.draw(m_text);	// Draws the text to the screen.
}

void Label::getFocus()
{
	m_text.setColor(sf::Color(236, 0, 24));	// Sets the colour of the text to red.
	m_hasFocus = true;	// Gives the text focus, this will be shared with what the label is referencing.
}

void Label::loseFocus()
{
	m_text.setColor(sf::Color(0, 0, 0));	// Sets the colour of the text to black.
	m_hasFocus = false;	// Takes focus from the text, this will be shared with what the label is referencing.
}

void Label::moveRight()
{
	m_text.setPosition(m_text.getPosition().x + 1, m_text.getPosition().y);	// Moves the text by positive one along the x-axis, the y-axis is unchanged.
}

void Label::moveLeft()
{
	m_text.setPosition(m_text.getPosition().x - 1, m_text.getPosition().y);	// Moves the text by negative one along the x-axis, the y-axis is unchanged.
}

#pragma endregion