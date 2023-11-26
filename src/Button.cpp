#include "../include/Button.hpp"

#include "SFML/Graphics.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/ButtonComponent.hpp"

Button::Button(std::string id, std::string text, sf::Vector2f position, sf::Vector2f size, sf::Color idleColor, sf::Color hoverColor) : BaseGameEntity(id) {

	m_buttonComponent = std::make_shared<ButtonComponent>(id, text, position, size, idleColor, hoverColor);
	AddComponent("ButtonComponent", m_buttonComponent);
}

void Button::Update(sf::RenderWindow& window, sf::Time& elapsed)
{
	BaseGameEntity::Update(window, elapsed);
}

void Button::Render(sf::RenderWindow& window) {
	BaseGameEntity::Render(window);
}

bool Button::isPressed() {
	return m_buttonComponent->isPressed();
}
