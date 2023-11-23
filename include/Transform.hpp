#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <SFML/Graphics.hpp>
#include <glm/vec2.hpp>

class Transform
{
public:
	Transform();
	
	void SetTransformable(sf::Transformable* transform);

	void SetPosition(const glm::vec2 position);
	glm::vec2 GetPosition() const;

	void SetRotation(float rotation);
	float GetRotation() const;

	void SetScale(const glm::vec2 scale);
	glm::vec2 GetScale() const;

	void Move(const glm::vec2 movement);
	void Rotate(float rotation);

	glm::vec2 GetForward() const;
private:

	sf::Transformable* m_transform;
};

#endif

