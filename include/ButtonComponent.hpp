#ifndef BUTTONCOMPONENT_H
#define BUTTONCOMPONENT_H

#include <SFML/Graphics.hpp>
#include "./IComponent.hpp"

class ButtonComponent : virtual public IComponent
{
public:
	ButtonComponent(std::string id, std::string text, sf::Vector2f position, sf::Vector2f size, sf::Color idleColor, sf::Color hoverColor);
	void Update(sf::RenderWindow& window, sf::Time& elapsed) override;
	void Render(sf::RenderWindow& window) override;

	bool isPressed();
protected:
	sf::RectangleShape m_shape;
	sf::Color m_idleColor;
	sf::Color m_hoverColor;
	bool m_isHovered;

	sf::Font m_font;
	sf::Text m_titleTxt;
};

#endif // !BUTTONCOMPONENT_H
