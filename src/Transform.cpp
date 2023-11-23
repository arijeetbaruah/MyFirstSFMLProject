#include "../include/Transform.hpp"
#include "../include/Constants.hpp"

#include <glm/gtx/transform2.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>

Transform::Transform() : m_transform(nullptr)
{
}

void Transform::SetTransformable(sf::Transformable* transform)
{
	m_transform = transform;
}

void Transform::SetPosition(const glm::vec2 position)
{
	m_transform->setPosition(position.x, position.y);
}

glm::vec2 Transform::GetPosition() const
{
	auto pos = m_transform->getPosition();
	return glm::vec2(pos.x, pos.y);
}

void Transform::SetRotation(const float rotation)
{
	m_transform->setRotation(rotation);
}

float Transform::GetRotation() const
{
	return m_transform->getRotation();
}

void Transform::SetScale(const glm::vec2 scale)
{
	m_transform->setScale(scale.x, scale.y);
}

glm::vec2 Transform::GetScale() const
{
	auto scale = m_transform->getScale();
	return glm::vec2(scale.x, scale.y);
}

void Transform::Move(const glm::vec2 movement)
{
	float speed = movement.length();
	
	float rotation = GetRotation();
	float angle = rotation == 0 ? 0 : (glm::pi<float>() / 180) * GetRotation();

	float cos = std::cos(angle);
	float sin = std::sin(angle);
	float newX = movement.x * cos - movement.y * sin;
	float newY = movement.x * sin + movement.y * cos;

	if (newX == newY && newX == 0)
	{
		return;
	}

	auto newMovement = glm::normalize(glm::vec2(newX, newY));

	m_transform->move(sf::Vector2f(newMovement.x, newMovement.y) * speed);
}

void Transform::Rotate(float rotation)
{
	m_transform->rotate(rotation);
}

glm::vec2 Transform::GetForward() const
{
	glm::vec2 position = GetPosition();
	float rotation = GetRotation();
	float angle = rotation == 0 ? 0 : glm::pi<float>() / (360 * GetRotation());

	float x = std::sin(angle);
	float y = std::cos(angle);
	return glm::vec2(-x, -y);
}
