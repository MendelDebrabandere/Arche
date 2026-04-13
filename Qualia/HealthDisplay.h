#pragma once
#include "FoodComponent.h"
#include "Subject.h"

namespace arche
{
	class TextComponent;
}

class AvatarComponent;

class HealthDisplay final : public arche::Component, public arche::Observer<int>
{
public:
	HealthDisplay() = default;
	~HealthDisplay() override;

	HealthDisplay(const HealthDisplay& other) = delete;
	HealthDisplay(HealthDisplay&& other) = delete;
	HealthDisplay& operator=(const HealthDisplay& other) = delete;
	HealthDisplay& operator=(HealthDisplay&& other) = delete;

	void Initialize() override;
	void SetSubject(arche::Subject<int>* healthSubj);

	int GetHP() const;

private:

	void HandleEvent(int healthDelta) override;
	void OnSubjectDestroy() override;
	void UpdateText();

	int m_HP{};
	arche::Subject<int>* m_pSubject{};

	arche::TextComponent* m_pText{};
};

