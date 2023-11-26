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
	BaseGameEntity(std::string entityID);
	virtual ~BaseGameEntity();

	std::string GetID() { return m_entityID; }

	virtual void Render(sf::RenderWindow& window);
	virtual void Update(sf::RenderWindow& window, sf::Time& elapsed);

	virtual void OnCollision(std::shared_ptr<BaseGameEntity> other) {}

	void AddComponent(std::string id, std::shared_ptr<IComponent> component);
	Transform* GetTransform();
	void SetTransform(Transform* transform);
	virtual sf::FloatRect GetBoundingBox() const { return sf::FloatRect(); }

protected:
	std::string m_entityID;
	std::unordered_map<std::string, std::shared_ptr<IComponent>> m_components;

	Transform* m_tranform;
};

#endif
