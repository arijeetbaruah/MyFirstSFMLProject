#include "ResourceManager.hpp"

void ResourceManager::Initialize()
{
	textureManager = std::make_unique<TextureManager>();
}
