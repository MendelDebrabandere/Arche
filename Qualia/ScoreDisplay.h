#pragma once
#include "FoodComponent.h"
#include "Subject.h"

namespace arche
{
	class TextComponent;
}

class AvatarComponent;

class ScoreDisplay final : public arche::Component, public arche::Observer<FoodComponent::FoodType>
{
public:
	ScoreDisplay() = default;
	~ScoreDisplay() override ;

	ScoreDisplay(const ScoreDisplay& other) = delete;
	ScoreDisplay(ScoreDisplay&& other) = delete;
	ScoreDisplay& operator=(const ScoreDisplay& other) = delete;
	ScoreDisplay& operator=(ScoreDisplay&& other) = delete;

	void Initialize() override;
	void SetPlayer(AvatarComponent* player);

	int GetScore() const;

private:

	void HandleEvent(FoodComponent::FoodType type) override;
	void OnSubjectDestroy() override;
	void UpdateScoreText();

	int m_score{};
	AvatarComponent* m_Player{};

	arche::TextComponent* m_pText{};
};

