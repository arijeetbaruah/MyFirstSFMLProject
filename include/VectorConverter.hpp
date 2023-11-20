#ifndef VECTORCONVERTER_H
#define VECTORCONVERTER_H

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>

class VectorConverter
{
public:
	// Convert SFML Vector to GLM Vector
	static glm::vec2 sfmlToGlm(const sf::Vector2f& sfmlVector);

	// Convert GLM Vector to SFML Vector
	static sf::Vector2f glmToSfml(const glm::vec2& glmVector);
};

#endif

