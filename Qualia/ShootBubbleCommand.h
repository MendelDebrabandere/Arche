#pragma once
#include "Command.h"
#include "GameObject.h"

class ShootBubbleCommand final : public arche::Command
{
public:
	explicit ShootBubbleCommand(arche::GameObject* go)
		: m_pGo{ go }
	{}

	void Execute() override;
private:
	arche::GameObject* m_pGo{};
};
