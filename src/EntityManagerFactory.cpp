#include "../include/EntityManagerFactory.hpp"
#include "../include/Player.hpp"
#include "../include/Asteroid.hpp"
#include "../include/Logger.hpp"

EntityManagerFactory::EntityManagerFactory()
{
	AddMapping("Player", [](std::string id) {
		return std::make_shared<Player>(id);
	});

	AddMapping("Asteroid", [](std::string id) {
		return std::make_shared<Asteroid>(id);
	});
}

std::shared_ptr<BaseGameEntity> EntityManagerFactory::GetEntity(std::string type, std::string id)
{
	if (m_mapper.find(type) != m_mapper.end()) {
		return m_mapper[type](id);
	}

	Logger::GetInstance()->log(LogLevel::ERROR, "[EntityManagerFactory] Invalid type:" + type);
	return nullptr;
}

void EntityManagerFactory::AddMapping(const std::string& key, std::function<std::shared_ptr<BaseGameEntity>(const std::string id)> func)
{
	m_mapper[key] = func;
}
