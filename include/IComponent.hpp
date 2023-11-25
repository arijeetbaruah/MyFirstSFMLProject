#ifndef ICOMPONENT_H
#define ICOMPONENT_H

#include <SFML/Graphics/RenderWindow.hpp>

class IComponent
{
public:
	virtual void Render(sf::RenderWindow& window) {};
	virtual void Update(sf::RenderWindow& window, sf::Time& elapsed) {};
};

#endif
