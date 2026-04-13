#pragma once
#include "Component.h"
#include "SpriteDataPreset.h"

class FoodComponent final : public arche::Component
{
public:
	enum class FoodType
	{
		Melon,
		Fries
	};

	FoodComponent() = default;
	~FoodComponent() override;

	FoodComponent(const FoodComponent& other) = delete;
	FoodComponent(FoodComponent&& other) = delete;
	FoodComponent& operator=(const FoodComponent& other) = delete;
	FoodComponent& operator=(FoodComponent&& other) = delete;

	void Initialize() override;
	void Update() override;

	void SetFoodType(FoodType type);

private:
	enum class State
	{
		Food,
		Points
	};

	FoodType m_MyType{};
	State m_CurrState{ State::Food };

	float m_Timer{};

	static float m_SpriteScale;
	static arche::SpriteDataPreset m_GreenScore100;
	static arche::SpriteDataPreset m_GreenScore200;
	static arche::SpriteDataPreset m_BlueScore100;
	static arche::SpriteDataPreset m_BlueScore200;
};
