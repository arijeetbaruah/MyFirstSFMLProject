#ifndef ENTITYMANAGERFACTORY_H
#define ENTITYMANAGERFACTORY_H

#include <map>
#include <memory>
#include "BaseGameEntity.hpp"
#include <functional>

class EntityManagerFactory
{
public:
	EntityManagerFactory();
	std::shared_ptr<BaseGameEntity> GetEntity(std::string type, std::string id);

private:
	std::map<std::string, std::function<std::shared_ptr<BaseGameEntity>(const std::string id)>> m_mapper;
	void AddMapping(const std::string& key, std::function<std::shared_ptr<BaseGameEntity>(const std::string id)> func);
};

#endif // !ENTITYMANAGER_H
