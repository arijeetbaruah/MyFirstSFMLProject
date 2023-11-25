#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "./BaseGameEntity.hpp"

class Sprite2DComponent;

class Player : public virtual BaseGameEntity
{
public:
	Player(std::string id);
	
	void Update(sf::RenderWindow& window, sf::Time& elapsed) override;
	sf::FloatRect GetBoundingBox() const override;
	void OnCollision(std::shared_ptr<BaseGameEntity> other) override;

private:
	std::shared_ptr<Sprite2DComponent> m_spriteComponent;
};

#endif
