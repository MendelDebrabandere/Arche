#pragma once
#include <glm/vec2.hpp>

#include "Component.h"
#include "SpriteDataPreset.h"

class BubbleComponent final : public arche::Component
{
public:
	enum class BubbleState
	{
		Shooting,
		Hovering,
		ReachedTop,
		Popping,
		EnemyDying
	};

	BubbleComponent() = default;
	~BubbleComponent() override = default;

	BubbleComponent(const BubbleComponent& other) = delete;
	BubbleComponent(BubbleComponent&& other) = delete;
	BubbleComponent& operator=(const BubbleComponent& other) = delete;
	BubbleComponent& operator=(BubbleComponent&& other) = delete;

	void Initialize() override;
	void Update() override;
	void SetShootDirection(bool right);

	BubbleState GetState() const;
	bool HasEnemyInside() const;

	void Pop(bool byPlayer);

	void SetBlue(bool value);

private:
	BubbleState m_CurrentState{ BubbleState::Shooting };

	void PickUpEnemy(arche::GameObject* go);

	float m_Timer{};
	bool m_DirectionRight{};

	//This is a bool and not a state
	//It still has to finish shooting, hovering and reach top
	//with an enemy inside
	bool m_HasEnemyInside{};
	bool m_ZenChan{true};

	glm::vec2 m_RandomGoToPos{};

	bool m_Blue{ false };

	static float m_SpriteScale;
	static arche::SpriteDataPreset m_GreenZenChan;
	static arche::SpriteDataPreset m_BlueZenChan;
	static arche::SpriteDataPreset m_GreenMaita;
	static arche::SpriteDataPreset m_BlueMaita;
	static arche::SpriteDataPreset m_GreenHover;
	static arche::SpriteDataPreset m_BlueHover;
	static arche::SpriteDataPreset m_Pop;
	static arche::SpriteDataPreset m_DeadZenChan;
	static arche::SpriteDataPreset m_DeadMaita;
};
