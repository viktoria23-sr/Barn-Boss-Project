#pragma once
#include "Command.h"
#include <print>

class HarvestCommand final : public Command
{
public:
	HarvestCommand(Game& game_) : Command(game_) {}

	void execute(const std::vector<std::string>& args) override;
};

