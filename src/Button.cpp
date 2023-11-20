#include "../include/Button.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/VectorConverter.hpp"

Button::Button(std::string text, glm::vec2 position, glm::vec2 size, sf::Color idleColor, sf::Color hoverColor)
	: idleColor(idleColor), hoverColor(hoverColor), isHovered(false) {
	shape.setPosition(VectorConverter::glmToSfml(position));
	shape.setSize(VectorConverter::glmToSfml(size));
	shape.setFillColor(idleColor);

	if (ResourceManager::GetInstance()->LoadFont("Roboto-Black.ttf", font))
	{
		titleTxt.setFont(font);
		titleTxt.setStyle(sf::Text::Bold);
		titleTxt.setString(text);
		titleTxt.setCharacterSize(24);
		titleTxt.setFillColor(sf::Color::Black);
		titleTxt.setPosition(VectorConverter::glmToSfml(position + size / 4.f));
	}
}

void Button::Update(sf::RenderWindow& window) {
	sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

	isHovered = shape.getGlobalBounds().contains(mousePos);

	if (isHovered) {
		shape.setFillColor(hoverColor);
		titleTxt.setFillColor(sf::Color::White);
	}
	else {
		shape.setFillColor(idleColor);
		titleTxt.setFillColor(sf::Color::Black);
	}
}

void Button::Render(sf::RenderWindow* window) {
	window->draw(shape);
	window->draw(titleTxt);
}

bool Button::isPressed() {
	return isHovered && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}
