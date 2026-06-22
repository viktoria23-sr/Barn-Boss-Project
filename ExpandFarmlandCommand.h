#pragma once
#include "Command.h"
#include <print>

class ExpandFarmlandCommand final : public Command
{
public:
	ExpandFarmlandCommand(Game& game_) : Command(game_) {}

	void execute(const std::vector<std::string>& args) override;
};

