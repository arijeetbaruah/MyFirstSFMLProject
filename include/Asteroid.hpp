#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>
#include "./BaseGameEntity.hpp"

class Sprite2DComponent;

class Asteroid : public virtual BaseGameEntity
{
public:
	Asteroid(std::string id);

	sf::FloatRect GetBoundingBox() const override;

private:
	std::shared_ptr<Sprite2DComponent> m_spriteComponent;
	sf::Transformable* m_transformable;
};

#endif // !ASTEROID_H
