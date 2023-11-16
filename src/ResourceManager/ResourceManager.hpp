#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "../Singleton.h"
#include "TextureManager.hpp"

class ResourceManager : public Singleton<ResourceManager>
{
public:
	void Initialize();

	std::unique_ptr<TextureManager> textureManager;
};

#endif
