#pragma once
#include "Component.h"
#include "SpriteDataPreset.h"

class MaitaComponent final : public arche::Component
{
public:
	MaitaComponent();
	~MaitaComponent() override = default;

	MaitaComponent(const MaitaComponent& other) = delete;
	MaitaComponent(MaitaComponent&& other) = delete;
	MaitaComponent& operator=(const MaitaComponent& other) = delete;
	MaitaComponent& operator=(MaitaComponent&& other) = delete;

	void Initialize() override;
	void Update() override;

private:
	bool m_Throwing{};
	float m_RockThrowingTimer{};

	static float m_SpriteScale;
	static arche::SpriteDataPreset m_WalkingPreset;
	static arche::SpriteDataPreset m_AttackingPreset;
};
