#ifndef ICOMPONENT_H
#define ICOMPONENT_H

class IComponent
{
public:
	virtual ~IComponent() {}

	virtual void Render(sf::RenderWindow* window) {};
	virtual void Update(sf::Time& elapsed) {};
};

#endif
