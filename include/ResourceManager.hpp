#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <string>
#include <SFML/Graphics.hpp>
#include "./Singleton.hpp"

class ResourceManager : public Singleton<ResourceManager>
{
public:
	sf::Texture GetTexture(std::string file) const;
	sf::Font LoadFont(std::string fontPath) const;
};

#endif
