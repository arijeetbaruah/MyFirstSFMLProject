#ifndef BaseGameEntity_H
#define BaseGameEntity_H

#include<vector>
#include<memory>
#include <unordered_map> 
#include <SFML/Graphics.hpp>
#include "./IComponent.hpp"
#include "./Transform.hpp"

class BaseGameEntity
{
public:
	BaseGameEntity(std::string entityID, sf::Transformable* transform);
	virtual ~BaseGameEntity();

	virtual void Render(sf::RenderWindow* window);
	virtual void Update(sf::Time& elapsed);

	virtual void OnCollision(BaseGameEntity* a, BaseGameEntity* b) {}

	void AddComponent(std::string id, std::shared_ptr<IComponent> component);
	Transform* GetTransform() const;

protected:
	std::string m_entityID;
	std::unordered_map<std::string, std::shared_ptr<IComponent>> m_components;

	Transform* m_tranform;
};

#endif
