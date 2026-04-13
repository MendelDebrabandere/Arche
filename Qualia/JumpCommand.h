#pragma once
#include "Command.h"
#include "GameObject.h"

class JumpCommand final : public arche::Command
{
public:
	explicit JumpCommand(arche::GameObject* go, float speed)
		:m_pGo{ go }
		, m_Speed{ speed }
	{}

	void Execute() override;
private:
	arche::GameObject* m_pGo{};
	float m_Speed{};
};
