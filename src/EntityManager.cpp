#include "../include/EntityManager.hpp"

EntityManager::EntityManager()
{
	m_factory = new EntityManagerFactory();
}

EntityManager::~EntityManager()
{
	delete m_factory;
	m_factory = 0;
}

std::shared_ptr<BaseGameEntity> EntityManager::CreateEntity(std::string type, std::string id)
{
	std::shared_ptr<BaseGameEntity> entity = m_factory->GetEntity(type, id);
	m_entities.emplace(id, entity);

	return entity;
}

void EntityManager::AddEntity(std::shared_ptr<BaseGameEntity> entity)
{
	m_entities.emplace(entity->GetID(), entity);
}

std::shared_ptr<BaseGameEntity> EntityManager::GetEntity(std::string id)
{
	return m_entities[id];
}

void EntityManager::Render(sf::RenderWindow& window)
{
	for (auto it = m_entities.begin(); it != m_entities.end(); it++)
	{
		it->second->Render(window);
	}
}

void EntityManager::Update(sf::RenderWindow& window, sf::Time& elapsed)
{
	for (auto it = m_entities.begin(); it != m_entities.end(); it++)
	{
		it->second->Update(window, elapsed);
	}

	for (auto it1 = m_entities.begin(); it1 != m_entities.end(); it1++)
	{
		for (auto it2 = it1; it2 != m_entities.end(); it2++)
		{
			if (it1 == it2)
			{
				continue;
			}

			auto boundingBox1 = it1->second->GetBoundingBox();
			auto boundingBox2 = it2->second->GetBoundingBox();

 			if (boundingBox1.intersects(boundingBox2))
			{
				it1->second->OnCollision(it2->second);
				it2->second->OnCollision(it1->second);
			}
		}
	}
}
