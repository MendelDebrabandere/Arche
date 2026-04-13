#pragma once
#include "Scene.h"

class Block final
{
public:
	static arche::GameObject* CreateBlock(arche::Scene* pScene, const glm::vec2& spawnPos, int level);
};
