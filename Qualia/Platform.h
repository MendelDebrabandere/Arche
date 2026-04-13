#pragma once
#include "Scene.h"

class Platform final
{
public:
	static arche::GameObject* CreatePlatform(arche::Scene* pScene, const glm::vec2& spawnPos, int level);
};
