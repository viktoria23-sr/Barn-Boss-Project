#pragma once
#include "Command.h"
#include <print>

class CheckScoreCommand final : public Command
{
public:
	CheckScoreCommand(Game& game_) : Command(game_) {}

	void execute(const std::vector<std::string>& args) override;
};

