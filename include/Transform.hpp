#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <SFML/Graphics.hpp>

class Transform
{
public:
	Transform();
	
	void SetTransformable(sf::Transformable* transform);

	void SetPosition(const sf::Vector2f  position);
	sf::Vector2f  GetPosition() const;

	void SetRotation(float rotation);
	float GetRotation() const;

	void SetScale(const sf::Vector2f  scale);
	sf::Vector2f GetScale() const;

	void Rotate(float rotation);

	sf::Vector2f GetForward() const;
private:

	sf::Transformable* m_transform;
};

#endif

