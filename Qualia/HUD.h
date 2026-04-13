#pragma once
#include "PlayerMaitaComponent.h"
#include "Scene.h"

class AvatarComponent;

class HUD final
{
public:
	static arche::GameObject* CreateHUD(arche::Scene* pScene, AvatarComponent* avatarComp, PlayerMaitaComponent* maitaComp = nullptr);
};
