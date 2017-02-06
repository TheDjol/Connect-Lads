#include "Widget.h"

Button::Button()
{

}

Button::Button(sf::Texture *texture, std::string *text, sf::Vector2f *position, sf::Font *font) :
	m_position(*position),
	m_texture(*texture),
	m_text(*text, *font, 28)
{
	m_sprite.setTexture(*texture);
	m_sprite.setPosition(*position);
	m_text.setPosition(m_sprite.getPosition().x + 35, m_sprite.getPosition().y + 5);
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

void Button::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);
	window.draw(m_text);
}

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




