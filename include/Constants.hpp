#ifndef CONSTANTS_H
#define CONSTANTS_H

const long PI = 3.1415926536f;

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
    return PI / 180;
}

#endif

