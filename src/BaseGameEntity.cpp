#include "../include/BaseGameEntity.hpp"
#include "../include/Sprite2DComponent.hpp"

BaseGameEntity::BaseGameEntity(std::string entityID, sf::Transformable* transform)
{
	m_tranform = new Transform();
	m_entityID = entityID;
}

BaseGameEntity::~BaseGameEntity()
{
	delete m_tranform;
	m_tranform = nullptr;
}

void BaseGameEntity::Render(sf::RenderWindow& window)
{
	for (auto it = m_components.begin(); it != m_components.end(); it++)
	{
		it->second.get()->Render(window);
	}
}

void BaseGameEntity::Update(sf::RenderWindow& window, sf::Time& elapsed)
{
	for (auto it = m_components.begin(); it != m_components.end(); it++)
	{
		it->second.get()->Update(window, elapsed);
	}
}

void BaseGameEntity::AddComponent(std::string id, std::shared_ptr<IComponent> component)
{
	m_components.insert_or_assign(id, component);
}

Transform* BaseGameEntity::GetTransform() const
{
	return m_tranform;
}
