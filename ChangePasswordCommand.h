#pragma once
#include "Command.h"
#include <print>

class ChangePasswordCommand final : public Command
{
public:
	ChangePasswordCommand(Game& game_) : Command(game_) {}

	void execute(const std::vector<std::string>& args) override;
};

