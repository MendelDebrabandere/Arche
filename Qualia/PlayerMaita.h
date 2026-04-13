#pragma once
#include "Scene.h"

class PlayerMaita final
{
public:
	static arche::GameObject* CreateMaita(arche::Scene* pScene, const glm::vec2& spawnPos);
};

