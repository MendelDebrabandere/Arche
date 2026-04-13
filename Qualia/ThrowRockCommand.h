#pragma once
#include "Command.h"
#include "GameObject.h"
#include "Timer.h"

class ThrowRockCommand final : public arche::Command
{
public:
	explicit ThrowRockCommand(arche::GameObject* go)
		: m_pGo{ go }
	{
		m_LastTimeThrew = arche::Time::GetInstance().GetTotal();
	}

	void Execute() override;
private:
	arche::GameObject* m_pGo{};

	float m_LastTimeThrew;
};
