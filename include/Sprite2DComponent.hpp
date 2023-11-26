#ifndef SPRITE2DGameEntity_H
#define SPRITE2DGameEntity_H

#include <SFML/Graphics.hpp>
#include "./IComponent.hpp"
#include "./Transform.hpp"

class Sprite2DComponent : virtual public IComponent
{
public:
	static const std::string ID;

	Sprite2DComponent(std::string texturePath, Transform* tranform);
	virtual ~Sprite2DComponent() {}
	void Render(sf::RenderWindow& window) override;
	void Update(sf::RenderWindow& window, sf::Time& elapsed) override;

	sf::FloatRect GetBoundingBox() const;
	sf::Sprite GetSprite() const;
protected:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	Transform* m_tranform;
};

#endif
