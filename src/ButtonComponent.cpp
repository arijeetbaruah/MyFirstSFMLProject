#include "../include/ButtonComponent.hpp"
#include "../include/ResourceManager.hpp"

ButtonComponent::ButtonComponent(std::string id, std::string text, sf::Vector2f position, sf::Vector2f size, sf::Color idleColor, sf::Color hoverColor)
	: m_idleColor(idleColor), m_hoverColor(hoverColor), m_isHovered(false)
{
	m_shape.setFillColor(idleColor);
	if (ResourceManager::GetInstance()->LoadFont("Roboto-Black.ttf", m_font))
	{
		m_titleTxt.setFont(m_font);
		m_titleTxt.setStyle(sf::Text::Bold);
		m_titleTxt.setString(text);
		m_titleTxt.setCharacterSize(24);
		m_titleTxt.setFillColor(sf::Color::Black);
		m_titleTxt.setPosition(position + size / 4.f);
	}
}

void ButtonComponent::Update(sf::RenderWindow& window, sf::Time& elapsed)
{
	sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

	m_isHovered = m_shape.getGlobalBounds().contains(mousePos);

	if (m_isHovered)
	{
		m_shape.setFillColor(m_hoverColor);
		m_titleTxt.setFillColor(sf::Color::White);
	}
	else
	{
		m_shape.setFillColor(m_idleColor);
		m_titleTxt.setFillColor(sf::Color::Black);
	}
}

void ButtonComponent::Render(sf::RenderWindow& window)
{
	window.draw(m_shape);
	window.draw(m_titleTxt);
}

bool ButtonComponent::isPressed()
{
	return m_isHovered && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}
