#include "../include/Sprite2DComponent.hpp"
#include "../include/ResourceManager.hpp"

const std::string Sprite2DComponent::ID = "Sprite2DComponent";

Sprite2DComponent::Sprite2DComponent(std::string texturePath, Transform* tranform) : m_tranform(tranform)
{
	ResourceManager* resourceManager = ResourceManager::GetInstance();

	if (resourceManager->GetTexture(texturePath, m_texture))
	{
		m_texture.setSmooth(true);
		m_sprite.setTexture(m_texture);
		m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2.f, m_sprite.getLocalBounds().height / 2.f);
	}

	tranform->SetTransformable(dynamic_cast<sf::Transformable*>(&m_sprite));
}

void Sprite2DComponent::Render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void Sprite2DComponent::Update(sf::RenderWindow& window, sf::Time& time)
{
	auto pos = m_tranform->GetPosition();
	auto scale = m_tranform->GetScale();
	m_sprite.setPosition(pos.x, pos.y);
	m_sprite.setRotation(m_tranform->GetRotation());
	m_sprite.setScale(scale.x, scale.y);
}

sf::Sprite Sprite2DComponent::GetSprite() const
{
	return m_sprite;
}

sf::FloatRect Sprite2DComponent::GetBoundingBox() const
{
	return m_sprite.getGlobalBounds();
}
