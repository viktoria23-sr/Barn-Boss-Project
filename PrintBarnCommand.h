#pragma once
#include "Command.h"
#include <print>

class PrintBarnCommand final : public Command
{
public:
	PrintBarnCommand(Game& game_) : Command(game_) {}

	void execute(const std::vector<std::string>& args) override;
};

