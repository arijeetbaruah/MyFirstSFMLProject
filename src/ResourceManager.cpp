#include <SFML/Graphics.hpp>
#include "../include/ResourceManager.hpp"
#include "../include/Logger.hpp"

const std::string ASSET_FILE = "../assets/";

sf::Texture ResourceManager::GetTexture(std::string texturePath) const
{
	std::string filePath = ASSET_FILE + "images/" + texturePath;

	sf::Texture texture;
	if (!texture.loadFromFile(filePath))
	{
		Logger::GetInstance()->log(LogLevel::ERROR, "Unable to open texture '" + texturePath + "'");
	}

	return texture;
}

sf::Font ResourceManager::LoadFont(std::string fontPath) const
{
	std::string filePath = ASSET_FILE + "fonts/" + fontPath;

	sf::Font font;
	if (font.loadFromFile(filePath))
	{
		Logger::GetInstance()->log(LogLevel::INFO, "Loaded Font:" + fontPath);

		return font;
	}

	Logger::GetInstance()->log(LogLevel::ERROR, "Unable to load Font:" + fontPath);
	return font;
}
