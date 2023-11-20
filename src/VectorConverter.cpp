#include "../include/VectorConverter.hpp"

glm::vec2 VectorConverter::sfmlToGlm(const sf::Vector2f& sfmlVector) {
	return glm::vec2(sfmlVector.x, sfmlVector.y);
}

// Convert GLM Vector to SFML Vector
sf::Vector2f VectorConverter::glmToSfml(const glm::vec2& glmVector) {
	return sf::Vector2f(glmVector.x, glmVector.y);
}
