#ifndef BUTTON_H

#include "SFML/Graphics.hpp"

class Button
{
public:
	Button(std::string text, sf::Vector2f position, sf::Vector2f size, sf::Color idleColor, sf::Color hoverColor);
	void Update(sf::RenderWindow& window);
	void Render(sf::RenderWindow* window);

	bool isPressed();

private:
	sf::RectangleShape shape;
	sf::Color idleColor;
	sf::Color hoverColor;
	bool isHovered;

	sf::Font font;
	sf::Text titleTxt;
};

#endif // !BUTTON_H
