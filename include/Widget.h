#ifndef WIDGET_H
#define WIDGET_H

#include "Xbox360Controller.h"

class Widget
{
public:
	Widget();
	~Widget();
	
	virtual void update(int noOfFrames);
	virtual void updateShape();
	virtual void processInput(GamePadState& controller);
	virtual void render(sf::RenderWindow& window);
	

};

#endif // !WIDGET_H

#ifndef BUTTON_H
#define BUTTON_H

class Button : public Widget
{
public:
	Button();
	Button(sf::Texture *texture, std::string *text, sf::Vector2f *position, sf::Font *font);
	~Button();

	void update();
	void render(sf::RenderWindow& window);

	void getFocus();
	void loseFocus();

	void moveRight();
	void moveLeft();

	sf::Vector2f m_position;
	sf::Sprite m_sprite;
	

private:
	
	sf::Texture m_texture;
	
	sf::Text m_text;
	sf::Font m_font;
	bool hasFocus;
	sf::FloatRect m_textRectangle;
	sf::FloatRect m_spriteRectangle;
};
#endif // !BUTTON_H

#ifndef RADIOBUTTON_H
#define RADIOBUTTON_H

class RadioButton : public Widget
{
public:
	RadioButton();
	RadioButton(sf::Texture *texture, sf::Vector2f *position);
	~RadioButton();

	void update();
	void render(sf::RenderWindow& window);

	void getFocus();
	void loseFocus();

	void moveRight();
	void moveLeft();

	sf::Vector2f m_position;
	sf::Sprite m_sprite;

private:
	sf::Texture m_texture;
	bool hasFocus;
	sf::FloatRect m_spriteRectangle;
};
#endif // !RADIOBUTTON_H

#ifndef SLIDER_H
#define SLIDER_H

class Slider : public Widget
{
public:
	Slider();
	Slider(sf::Texture *texture, sf::Vector2f *position);
	~Slider();

	void update();
	void render(sf::RenderWindow& window);

	void getFocus();
	void loseFocus();

	void moveRight();
	void moveLeft();

	sf::Vector2f m_position;
	sf::Sprite m_sprite;

private:
	sf::Texture m_texture;
	bool hasFocus;
	sf::FloatRect m_spriteRectangle;
	
	sf::CircleShape m_circle;
	sf::RectangleShape m_sliderBackground;
	sf::RectangleShape m_slider;
};
#endif // !SLIDER_H