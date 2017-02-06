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
	//void processInput(GamePadState& controller);
	void render(sf::RenderWindow& window);

	void getFocus();
	void loseFocus();


private:
	sf::Vector2f m_position;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Text m_text;
	sf::Font m_font;
	bool hasFocus;
};
#endif // ! BUTTON_H