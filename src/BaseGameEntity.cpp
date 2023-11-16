#include "../include/BaseGameEntity.hpp"
#include "../include/Sprite2DComponent.hpp"

BaseGameEntity::BaseGameEntity(std::string entityID)
{
	m_entityID = entityID;
}

void BaseGameEntity::Render(sf::RenderWindow* window)
{
	for (auto it = m_components.begin(); it != m_components.end(); it++)
	{
		it->get()->Render(window);
	}
}

void BaseGameEntity::Update(sf::Time& elapsed)
{
	for (auto it = m_components.begin(); it != m_components.end(); it++)
	{
		IComponent* component = it->get();

		component->SetPosition(GetPosition());
		component->SetRotation(GetRotation());
		component->SetScale(GetScale());

		component->Update(elapsed);
	}
}

void BaseGameEntity::AddComponent(std::shared_ptr<IComponent> component)
{
	m_components.push_back(component);
}

void BaseGameEntity::SetPosition(sf::Vector2f position)
{
	m_position = position;
}

sf::Vector2f BaseGameEntity::GetPosition() const
{
	return m_position;
}

void BaseGameEntity::SetRotation(float rotation)
{
	m_rotation = rotation;
}

float BaseGameEntity::GetRotation() const
{
	return m_rotation;
}

void BaseGameEntity::SetScale(sf::Vector2f scale)
{
	m_scale = scale;
}

sf::Vector2f BaseGameEntity::GetScale() const
{
	return m_scale;
}
