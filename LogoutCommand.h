#pragma once
#include "Command.h"
#include <print>

class LogoutCommand final : public Command
{
public:
	LogoutCommand(Game& game_) : Command(game_) {}

	void execute(const std::vector<std::string>& args) override;
};


