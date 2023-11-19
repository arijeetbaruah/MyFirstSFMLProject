#include "../include/Transform.hpp"
#include "../include/Constants.hpp"

Transform::Transform() : m_transform(nullptr)
{
}

void Transform::SetTransformable(sf::Transformable* transform)
{
	m_transform = transform;
}

void Transform::SetPosition(sf::Vector2f position)
{
	m_transform->setPosition(position);
}

sf::Vector2f Transform::GetPosition() const
{
	return m_transform->getPosition();
}

void Transform::SetRotation(const float rotation)
{
	m_transform->setRotation(rotation);
}

float Transform::GetRotation() const
{
	return m_transform->getRotation();
}

void Transform::SetScale(const sf::Vector2f scale)
{
	m_transform->setScale(scale);
}
sf::Vector2f Transform::GetScale() const
{
	return m_transform->getScale();
}

void Transform::Rotate(float rotation)
{
	m_transform->rotate(rotation);
}

sf::Vector2f Transform::GetForward() const
{
	float angle = GetRotation();
	float x = std::sin(angle);
	float y = std::cos(angle);
	return sf::Vector2f (-x, -y);
}
