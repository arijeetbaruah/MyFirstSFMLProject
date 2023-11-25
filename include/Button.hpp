#ifndef BUTTON_H

#include "SFML/Graphics.hpp"
#include "./BaseGameEntity.hpp"

class ButtonComponent;

class Button : public virtual BaseGameEntity
{
public:
	Button(std::string id, std::string text, sf::Vector2f position, sf::Vector2f size, sf::Color idleColor, sf::Color hoverColor);
	void Update(sf::RenderWindow& window, sf::Time& elapsed) override;
	void Render(sf::RenderWindow& window) override;

	bool isPressed();
protected:
	std::shared_ptr<ButtonComponent> m_buttonComponent;
};

#endif // !BUTTON_H
