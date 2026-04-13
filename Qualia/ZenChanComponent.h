#pragma once
#include "Component.h"
#include "SpriteDataPreset.h"

class ZenChanComponent final : public arche::Component
{
public:
	ZenChanComponent();
	~ZenChanComponent() override = default;

	ZenChanComponent(const ZenChanComponent& other) = delete;
	ZenChanComponent(ZenChanComponent&& other) = delete;
	ZenChanComponent& operator=(const ZenChanComponent& other) = delete;
	ZenChanComponent& operator=(ZenChanComponent&& other) = delete;

	void Initialize() override;
	void Update() override;

private:
	bool m_Charging{};
	float m_ChargingTimer{};

	static float m_SpriteScale;
	static arche::SpriteDataPreset m_WalkingPreset;
	static arche::SpriteDataPreset m_ChargingPreset;
};
