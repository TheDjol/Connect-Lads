#include "Widget.h"
#pragma region WidgetRegion
Widget::Widget()
{
}

Widget::~Widget()
{
}

void Widget::update(int noOfFrames)
{
}

void Widget::updateShape()
{
}

void Widget::processInput(GamePadState & controller)
{
}

void Widget::render(sf::RenderWindow & window)
{
}

#pragma endregion

#pragma region ButtonRegion

Button::Button()
{

}

Button::Button(sf::Texture *texture, std::string *text, sf::Vector2f *position, sf::Font *font) :
	m_position(*position),
	m_texture(*texture),
	m_text(*text, *font, 28)
{
	m_sprite.setTexture(*texture);

	// Gets the dimensions of the rectangle that contains the text.
	m_spriteRectangle = m_sprite.getLocalBounds();
	// Centres the origin of the text.
	m_sprite.setOrigin(m_spriteRectangle.left + m_spriteRectangle.width / 2.0f, m_spriteRectangle.top + m_spriteRectangle.height / 2.0f);

	m_sprite.setPosition(*position);

	// Gets the dimensions of the rectangle that contains the text.
	m_textRectangle = m_text.getLocalBounds();
	// Centres the origin of the text.
	m_text.setOrigin(m_textRectangle.left + m_textRectangle.width / 2.0f, m_textRectangle.top + m_textRectangle.height / 2.0f);

	m_text.setPosition(*position);
	m_text.setColor(sf::Color(0, 0, 0));
}

Button::~Button()
{
	
}

void Button::update()
{
	
}

void Button::getFocus()
{
	m_text.setColor(sf::Color(236, 0, 24));
	m_hasFocus = true;
}

void Button::loseFocus()
{
	m_text.setColor(sf::Color(0,0,0));
	m_hasFocus = false;
}

void Button::scaleButtons(float xScale, float yScale)
{
	m_sprite.setScale(xScale, yScale);
}

void Button::moveRight()
{
	m_sprite.setPosition(m_sprite.getPosition().x + 1, m_sprite.getPosition().y);
	m_text.setPosition(m_text.getPosition().x + 1, m_text.getPosition().y);
}

void Button::moveLeft()
{
	m_sprite.setPosition(m_sprite.getPosition().x - 1, m_sprite.getPosition().y);
	m_text.setPosition(m_text.getPosition().x - 1, m_text.getPosition().y);
}


void Button::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);
	window.draw(m_text);
}

#pragma endregion

#pragma region RadioButtonRegion

RadioButton::RadioButton()
{
}

RadioButton::RadioButton(sf::Texture * texture, sf::Vector2f * position) :
	m_position(*position),
	m_texture(*texture)
{
	m_sprite.setTexture(*texture);

	// Gets the dimensions of the rectangle that contains the text.
	m_spriteRectangle = m_sprite.getLocalBounds();
	// Centres the origin of the text.
	m_sprite.setOrigin(m_spriteRectangle.left + m_spriteRectangle.width / 2.0f, m_spriteRectangle.top + m_spriteRectangle.height / 2.0f);

	m_sprite.setPosition(*position);
}

RadioButton::~RadioButton()
{
}

void RadioButton::update()
{
}

void RadioButton::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

void RadioButton::getFocus()
{
	m_hasFocus = true;
}

void RadioButton::loseFocus()
{
	m_hasFocus = false;
}

void RadioButton::moveRight()
{
	m_sprite.setPosition(m_sprite.getPosition().x + 1, m_sprite.getPosition().y);
}

void RadioButton::moveLeft()
{
	m_sprite.setPosition(m_sprite.getPosition().x - 1, m_sprite.getPosition().y);
}

#pragma endregion

#pragma region SliderRegion


Slider::Slider()
{

}

Slider::Slider(sf::Vector2f * position, int numOfSegments) :
	m_position(*position),
	m_numOfSegments(numOfSegments - 1)	// Using numOfSegments -1 as we are using zero based numbering.
{
	float circleSize = 15.0f;
	float sizeY = 20.0f;
	float sizeX = 150.0f;
	m_sliderBackground.setPosition(m_position);
	m_slider.setPosition(m_position);
	m_circle.setPosition(m_position);

	m_sliderBackground.setFillColor(sf::Color::Blue);
	m_slider.setFillColor(sf::Color::Black);
	m_circle.setFillColor(sf::Color::Black);

	m_sliderBackground.setSize(sf::Vector2f(sizeX, sizeY));
	m_slider.setSize(sf::Vector2f(sizeX, sizeY));
	m_circle.setRadius(circleSize);

	m_currentSegment = m_numOfSegments;
}

Slider::~Slider()
{
}

void Slider::update()
{
	m_circle.setPosition(m_slider.getPosition().x + m_slider.getLocalBounds().width - (m_circle.getLocalBounds().width / 2), m_slider.getPosition().y - (m_circle.getLocalBounds().height / 6));
}

void Slider::render(sf::RenderWindow & window)
{
	window.draw(m_sliderBackground);
	window.draw(m_slider);
	window.draw(m_circle);
}

void Slider::getFocus()
{
	m_slider.setFillColor(sf::Color(236, 0, 24));
	m_hasFocus = true;
}

void Slider::loseFocus()
{
	m_slider.setFillColor(sf::Color(0, 0, 0));
	m_hasFocus = false;
}

void Slider::moveRight()
{
	m_sliderBackground.setPosition(m_slider.getPosition().x + 1, m_slider.getPosition().y);
	m_slider.setPosition(m_slider.getPosition().x + 1, m_slider.getPosition().y);
	m_circle.setPosition(m_circle.getPosition().x + 1, m_circle.getPosition().y);
}

void Slider::moveLeft()
{
	m_sliderBackground.setPosition(m_sliderBackground.getPosition().x - 1, m_sliderBackground.getPosition().y);
	m_slider.setPosition(m_slider.getPosition().x - 1, m_slider.getPosition().y);
	m_circle.setPosition(m_circle.getPosition().x - 1, m_circle.getPosition().y);
}

int Slider::incrementSlider()
{
	//if (m_slider.getLocalBounds().width < 150)
	//{
	//	m_slider.setSize(sf::Vector2f(m_slider.getSize().x + 0.05f, m_slider.getSize().y));
	//	m_circle.setPosition(m_slider.getPosition().x + m_slider.getLocalBounds().width, m_slider.getPosition().y);
	//}

	if (m_currentSegment < m_numOfSegments)
	{
		m_currentSegment++;
		m_slider.setSize(sf::Vector2f((m_sliderBackground.getSize().x / m_numOfSegments) * m_currentSegment, m_slider.getSize().y));
		m_circle.setPosition(m_slider.getPosition().x + m_slider.getLocalBounds().width, m_slider.getPosition().y);
	}

	return m_currentSegment;
}

int Slider::decrementSlider()
{
	//if (m_slider.getSize().x > 0)
	//{
	//	m_slider.setSize(sf::Vector2f(m_slider.getSize().x - 0.05f, m_slider.getSize().y));
	//	m_circle.setPosition(m_slider.getPosition().x + m_slider.getLocalBounds().width, m_slider.getPosition().y);
	//}

	if (m_currentSegment > 0)
	{
		m_currentSegment--;
		m_slider.setSize(sf::Vector2f((m_sliderBackground.getSize().x / m_numOfSegments) * m_currentSegment, m_slider.getSize().y));
		m_circle.setPosition(m_slider.getPosition().x + m_slider.getLocalBounds().width, m_slider.getPosition().y);
	}

	return m_currentSegment;
}

#pragma endregion

#pragma region LabelRegion

Label::Label()
{
}

Label::Label(std::string * text, sf::Font * font, sf::Vector2f *position) :
	m_font(*font),
	m_position(*position),
	m_text(*text, *font, 38)
{
	// Gets the dimensions of the rectangle that contains the text.
	m_textRectangle = m_text.getLocalBounds();
	// Centres the origin of the text.
	m_text.setOrigin(m_textRectangle.left + m_textRectangle.width / 2.0f, m_textRectangle.top + m_textRectangle.height / 2.0f);
	
	m_text.setPosition(*position);
	m_text.setColor(sf::Color(0, 0, 0));
}

Label::~Label()
{

}

void Label::update()
{
}

void Label::render(sf::RenderWindow & window)
{
	window.draw(m_text);
}

void Label::getFocus()
{
	m_text.setColor(sf::Color(236, 0, 24));
	m_hasFocus = true;
}

void Label::loseFocus()
{
	m_text.setColor(sf::Color(0, 0, 0));
	m_hasFocus = false;
}

void Label::moveRight()
{
	m_text.setPosition(m_text.getPosition().x + 1, m_text.getPosition().y);
}

void Label::moveLeft()
{
	m_text.setPosition(m_text.getPosition().x - 1, m_text.getPosition().y);
}

#pragma endregion