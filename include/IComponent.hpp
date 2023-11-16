#ifndef ICOMPONENT_H
#define ICOMPONENT_H

class IComponent
{
public:
	virtual ~IComponent() {}

	virtual void Render(sf::RenderWindow* window) {};
	virtual void Update(sf::Time& elapsed) {};

	virtual void SetPosition(sf::Vector2f position) {}
	virtual sf::Vector2f GetPosition() const { return sf::Vector2f(); }

	virtual void SetRotation(float rotation) {}
	virtual float GetRotation() const { return 0; }

	virtual void SetScale(sf::Vector2f scale) {}
	virtual sf::Vector2f GetScale() const { return sf::Vector2f(); }
};

#endif
