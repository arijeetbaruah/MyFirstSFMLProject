#ifndef BaseGameEntity_H
#define BaseGameEntity_H

#include<vector>
#include<memory>
#include <unordered_map> 
#include <SFML/Graphics.hpp>
#include "./IComponent.hpp"

class BaseGameEntity
{
public:
	BaseGameEntity(std::string entityID);
	virtual ~BaseGameEntity() {}

	virtual void Render(sf::RenderWindow* window);
	virtual void Update(sf::Time& elapsed);

	virtual void OnCollision(BaseGameEntity* a, BaseGameEntity* b) {}

	void AddComponent(std::string id, std::shared_ptr<IComponent> component);

	void SetPosition(sf::Vector2f position);
	sf::Vector2f GetPosition() const;

	void SetRotation(float rotation);
	float GetRotation() const;

	void SetScale(sf::Vector2f scale);
	sf::Vector2f GetScale() const;

protected:
	std::string m_entityID;
	std::unordered_map<std::string, std::shared_ptr<IComponent>> m_components;

	sf::Vector2f m_position;
	float m_rotation;
	sf::Vector2f m_scale;
};

#endif
