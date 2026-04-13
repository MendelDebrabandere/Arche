#pragma once
#include "Scene.h"
#include "FoodComponent.h"

class Food final
{
public:

	static arche::GameObject* CreateFood(arche::Scene* pScene, const arche::GameObject* transformingObj, FoodComponent::FoodType type);
};

