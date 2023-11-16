#include "../include/Sprite2DComponent.hpp"
#include "../include/ResourceManager.hpp"

Sprite2DComponent::Sprite2DComponent(std::string texturePath)
{
	ResourceManager* resourceManager = ResourceManager::GetInstance();

	m_texture = resourceManager->GetTexture(texturePath);
	m_texture.setSmooth(true);
	m_sprite.setTexture(m_texture);
}

void Sprite2DComponent::Render(sf::RenderWindow* window)
{
	window->draw(m_sprite);
}

void Sprite2DComponent::Update(sf::Time& time)
{
}

void Sprite2DComponent::SetPosition(sf::Vector2f position)
{
	m_sprite.setPosition(position);
}

sf::Vector2f Sprite2DComponent::GetPosition() const
{
	return m_sprite.getPosition();
}

void Sprite2DComponent::SetRotation(float rotation)
{
	m_sprite.setRotation(rotation);
}

float Sprite2DComponent::GetRotation() const
{
	return m_sprite.getRotation();
}

void Sprite2DComponent::SetScale(sf::Vector2f scale)
{
	m_sprite.setScale(scale);
}

sf::Vector2f Sprite2DComponent::GetScale() const
{
	return m_sprite.getScale();
}
