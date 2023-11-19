#include "../include/Player.hpp"
#include <memory>
#include "../include/ResourceManager.hpp"
#include "../include/Sprite2DComponent.hpp"

const float playerSpeed = 3;
const float rotSpeed = 3;

Player::Player() : BaseGameEntity("player", nullptr)
{
	std::shared_ptr<IComponent> spriteComponent = std::shared_ptr<Sprite2DComponent>(new Sprite2DComponent("player.png", GetTransform()));
	AddComponent(Sprite2DComponent::ID, spriteComponent);
	GetTransform()->SetPosition(sf::Vector2(1000.f, 500.f));
	GetTransform()->SetScale(sf::Vector2(0.3f, 0.3f));
}

void Player::Update(sf::Time& elapsed)
{
	BaseGameEntity::Update(elapsed);

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
		auto transform = GetTransform();
		transform->SetPosition(transform->GetPosition() + transform->GetForward() * playerSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		// left key is pressed: move our character
		auto transform = GetTransform();
		transform->SetPosition(transform->GetPosition() - transform->GetForward() * playerSpeed);
	}
}
