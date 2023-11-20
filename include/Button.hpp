#ifndef BUTTON_H

#include "SFML/Graphics.hpp"
#include <glm/vec2.hpp>

class Button
{
public:
	Button(std::string text, glm::vec2 position, glm::vec2 size, sf::Color idleColor, sf::Color hoverColor);
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
