#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <string>
#include <SFML/Graphics.hpp>
#include "./Singleton.hpp"

class ResourceManager : public Singleton<ResourceManager>
{
public:
	bool GetTexture(std::string filePath, sf::Texture& texture) const;
	bool LoadFont(std::string fontPath, sf::Font& font) const;
};

#endif
