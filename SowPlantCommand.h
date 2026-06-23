#pragma once
#include "Command.h"
#include <print>

class SowPlantCommand final : public Command
{
public:
	SowPlantCommand(Game& game_) : Command(game_) {}

	void execute(const std::vector<std::string>& args) override;
};

