#pragma once
#include "Command.h"
#include "GameObject.h"

class MoveLeftCommand final : public arche::Command
{
public:
	explicit MoveLeftCommand(arche::GameObject* go, float speed)
		:m_pGo{ go }
		, m_Speed{ speed }
	{}

	void Execute() override;
private:
	void Move();

	arche::GameObject* m_pGo{};
	float m_Speed{};
};

