#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "./Singleton.hpp"
#include <unordered_map>
#include <memory>
#include "./BaseGameEntity.hpp"
#include "./EntityManagerFactory.hpp"

class EntityManager : public Singleton<EntityManager>
{
public:
	EntityManager();
	~EntityManager();

	std::shared_ptr<BaseGameEntity> CreateEntity(std::string type, std::string id);
	void AddEntity(std::shared_ptr<BaseGameEntity> entity);
	std::shared_ptr<BaseGameEntity> GetEntity(std::string id);

	virtual void Render(sf::RenderWindow& window);
	virtual void Update(sf::RenderWindow& window, sf::Time& elapsed);

private:
	/// <summary>
	/// Container for GameEntities
	/// </summary>
	std::unordered_map<std::string, std::shared_ptr<BaseGameEntity>> m_entities;
	EntityManagerFactory* m_factory;
};

#endif // !ENTITYMANAGER_H
