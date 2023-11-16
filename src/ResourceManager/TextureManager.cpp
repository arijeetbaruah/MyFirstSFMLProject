#include "TextureManager.hpp"
#include "../Logger.hpp"

const std::string ASSET_FILE = "../assets/";

sf::Texture TextureManager::GetTexture(std::string texturePath)
{
	sf::Texture texture;
	if (!texture.loadFromFile(ASSET_FILE + texturePath))
	{
		Logger::GetInstance()->log(LogLevel::ERROR, "Unable to open texture '" + texturePath + "'");
	}

	return texture;
}
