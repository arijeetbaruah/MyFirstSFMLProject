#include "../include/Player.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/Sprite2DComponent.hpp"
#include <glm/vec2.hpp>
#include "../include/Logger.hpp"

const float playerSpeed = 3;
const float rotSpeed = 3;

Player::Player(std::string id) : BaseGameEntity(id)
{
	m_spriteComponent = std::shared_ptr<Sprite2DComponent>(new Sprite2DComponent("player.png", GetTransform()));
	AddComponent(Sprite2DComponent::ID, m_spriteComponent);
	GetTransform()->SetPosition(glm::vec2(1000.f, 500.f));
	GetTransform()->SetScale(glm::vec2(0.3f, 0.3f));
}

void Player::Update(sf::RenderWindow& window, sf::Time& elapsed)
{
	BaseGameEntity::Update(window, elapsed);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		// left key is pressed: move our character
		GetTransform()->Rotate(-rotSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		// left key is pressed: move our character
		GetTransform()->Rotate(rotSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		// left key is pressed: move our character
		GetTransform()->Move(glm::vec2(0, -1) * playerSpeed);
		/*auto transform = GetTransform();
		transform->SetPosition(transform->GetPosition() + transform->GetForward() * playerSpeed);*/
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		// left key is pressed: move our character
		GetTransform()->Move(glm::vec2(0, 1) * playerSpeed);
		/*auto transform = GetTransform();
		transform->SetPosition(transform->GetPosition() - transform->GetForward() * playerSpeed);*/
	}
}

sf::FloatRect Player::GetBoundingBox() const
{
	return m_spriteComponent->GetBoundingBox();
}

void Player::OnCollision(std::shared_ptr<BaseGameEntity> other)
{
	Logger::GetInstance()->log(LogLevel::INFO, "Collision: " + other->GetID());
}
