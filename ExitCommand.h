#pragma once
#include "Command.h"
#include <print>

class ExitCommand final : public Command
{
public:
	ExitCommand(Game& game_) : Command(game_) {}

	void execute(const std::vector<std::string>& args) override;
};

