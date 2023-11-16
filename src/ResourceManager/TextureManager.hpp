#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include "../Singleton.h"

class TextureManager
{
public:
	sf::Texture GetTexture(std::string file);
};

#endif
