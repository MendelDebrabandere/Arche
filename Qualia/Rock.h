#pragma once
#include "Scene.h"

class Rock final
{
public:

	static arche::GameObject* CreateRock(arche::Scene* pScene, const arche::GameObject* transformingObj, bool rightDir);
};

