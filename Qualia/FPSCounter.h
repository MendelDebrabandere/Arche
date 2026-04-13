#pragma once
#include "Component.h"

namespace arche
{
	class TextComponent;
}

class FPSCounter final : public arche::Component
{
public:
	FPSCounter() = default;
	~FPSCounter() override = default;

	FPSCounter(const FPSCounter& other) = delete;
	FPSCounter(FPSCounter&& other) = delete;
	FPSCounter& operator=(const FPSCounter& other) = delete;
	FPSCounter& operator=(FPSCounter&& other) = delete;

	void Update() override;
private:
	int m_AmountOfPassedFrames{};
	float m_AccuSec{};
	const float m_UpdateInterval{ 1.f };
	int m_FPS{};

	arche::TextComponent* m_pText{};
};

