#include "Widget.h"

Button::Button(sf::Texture texture, std::string text, sf::Vector2f position, sf::Font font) :
	m_position(position),
	m_texture(texture),
	m_text(text, font, 28)
{
	m_sprite.setTexture(texture);
}

Button::~Button()
{
	delete this;
}

void Button::update()
{
	
}

void Button::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}