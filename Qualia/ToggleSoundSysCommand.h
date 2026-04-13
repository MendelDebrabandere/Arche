#pragma once
#include "Command.h"

class ToggleSoundSysCommand final : public arche::Command
{
public:
	ToggleSoundSysCommand() = default;

	void Execute() override;
private:
	bool m_SoundIsOn{ true };
};
