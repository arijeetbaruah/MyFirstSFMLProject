#ifndef SPRITE2DGameEntity_H
#define SPRITE2DGameEntity_H

#include <SFML/Graphics.hpp>
#include "./IComponent.hpp"

class Sprite2DComponent : virtual public IComponent
{
public:
	Sprite2DComponent(std::string texturePath);
	virtual ~Sprite2DComponent() {}
	void Render(sf::RenderWindow* window) override;
	void Update(sf::Time& elapsed) override;

	void SetPosition(sf::Vector2f position);
	sf::Vector2f GetPosition() const;

	void SetRotation(float rotation);
	float GetRotation() const;

	void SetScale(sf::Vector2f scale);
	sf::Vector2f GetScale() const;
protected:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};

#endif
