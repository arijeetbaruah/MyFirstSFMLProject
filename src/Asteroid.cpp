#include "../include/Asteroid.hpp"
#include "../include/Sprite2DComponent.hpp"

Asteroid::Asteroid(std::string id) : BaseGameEntity(id, nullptr)
{
	m_spriteComponent = std::shared_ptr<Sprite2DComponent>(new Sprite2DComponent("Asteroid.png", GetTransform()));
	AddComponent(Sprite2DComponent::ID, m_spriteComponent);
	GetTransform()->SetPosition(glm::vec2(100.f, 500.f));
}

sf::FloatRect Asteroid::GetBoundingBox() const
{
	return m_spriteComponent->GetBoundingBox();
}
