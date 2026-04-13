#pragma once
#include "Command.h"

class StartSinglePlayerCommand final : public arche::Command
{
public:
	StartSinglePlayerCommand() = default;

	void Execute() override;
private:
};