#include "../include/Asteroid.hpp"
#include "../include/Sprite2DComponent.hpp"

Asteroid::Asteroid(std::string id) : BaseGameEntity(id)
{
	Transform* transform = GetTransform();
	m_spriteComponent = std::shared_ptr<Sprite2DComponent>(new Sprite2DComponent("Asteroid.png", transform));
	AddComponent(Sprite2DComponent::ID, m_spriteComponent);

	m_transformable = reinterpret_cast<sf::Transformable*>(&m_spriteComponent->GetSprite());
	transform->SetTransformable(m_transformable);

	transform->SetPosition(glm::vec2(100.f, 500.f));
}

sf::FloatRect Asteroid::GetBoundingBox() const
{
	return m_spriteComponent->GetBoundingBox();
}
