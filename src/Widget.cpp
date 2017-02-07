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
	hasFocus = true;
}

void Button::loseFocus()
{
	m_text.setColor(sf::Color(0,0,0));
	hasFocus = false;
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
	hasFocus = true;
}

void RadioButton::loseFocus()
{
	hasFocus = false;
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

Slider::Slider(sf::Texture * texture, sf::Vector2f * position) :
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

Slider::~Slider()
{

}

void Slider::update()
{

}

void Slider::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

void Slider::getFocus()
{

}

void Slider::loseFocus()
{

}

void Slider::moveRight()
{

}

void Slider::moveLeft()
{

}

#pragma endregion