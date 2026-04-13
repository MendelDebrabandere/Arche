#pragma once
#include "Command.h"

class StartVersusCommand final : public arche::Command
{
public:
	StartVersusCommand() = default;

	void Execute() override;
private:
};