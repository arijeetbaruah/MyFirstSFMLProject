#include "../include/Player.hpp"
#include <memory>
#include "../include/ResourceManager.hpp"
#include "../include/Sprite2DComponent.hpp"

const float playerSpeed = 3;

Player::Player() : BaseGameEntity("player")
{
	std::shared_ptr<IComponent> spriteComponent = std::shared_ptr<Sprite2DComponent>(new Sprite2DComponent("player.png"));
	AddComponent(Sprite2DComponent::ID, spriteComponent);
	SetPosition(sf::Vector2(1000.f, 500.f));
	//SetScale(sf::Vector2(0.3f, 0.3f));
}

void Player::Update(sf::Time& elapsed)
{
	BaseGameEntity::Update(elapsed);
	SetRotation(GetRotation() + 1);

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	//{
	//	// left key is pressed: move our character
	//	sf::Vector2f movementDirection(-1.f, 0.f);
	//	m_sprite.move(movementDirection * playerSpeed);
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	//{
	//	// left key is pressed: move our character
	//	sf::Vector2f movementDirection(1.f, 0.f);
	//	m_sprite.move(movementDirection * playerSpeed);
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	//{
	//	// left key is pressed: move our character
	//	sf::Vector2f movementDirection(0.f, -1.f);
	//	m_sprite.move(movementDirection * playerSpeed);
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	//{
	//	// left key is pressed: move our character
	//	sf::Vector2f movementDirection(0.f, 1.f);
	//	m_sprite.move(movementDirection * playerSpeed);
	//}
}
