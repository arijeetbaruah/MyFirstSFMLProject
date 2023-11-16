#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "./BaseGameEntity.hpp"

class Player : public virtual BaseGameEntity
{
public:
	Player();
	void Update(sf::Time& elapsed) override;
};

#endif
