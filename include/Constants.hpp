#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <glm/ext/scalar_constants.hpp>

float Dot(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

sf::Vector2f Cross(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
    return sf::Vector2f(v1.x * v2.y, v2.x * v1.y);
}

double DegreeToRadian(const double rad)
{
    return glm::pi<float>() / 180;
}

#endif

