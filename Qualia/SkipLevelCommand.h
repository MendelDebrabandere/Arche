#pragma once
#include "Command.h"

class SkipLevelCommand final : public arche::Command
{
public:
	explicit SkipLevelCommand()
	{}

	void Execute() override;
private:
	
};
