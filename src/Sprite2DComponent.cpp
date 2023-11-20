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

void Sprite2DComponent::Render(sf::RenderWindow* window)
{
	window->draw(m_sprite);
}

void Sprite2DComponent::Update(sf::Time& time)
{
	m_sprite.setPosition(m_tranform->GetPosition());
	m_sprite.setRotation(m_tranform->GetRotation());
	m_sprite.setScale(m_tranform->GetScale());
}
