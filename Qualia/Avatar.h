#pragma once
#include "Scene.h"

class Avatar final
{
public:
	static arche::GameObject* CreateAvatar(arche::Scene* pScene, const glm::vec2& spawnPos, bool green, bool coop);
};

