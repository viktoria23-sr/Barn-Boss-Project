#pragma once
#include "Command.h"
#include <print>

class ShowScoreboardCommand final : public Command
{
public:
	ShowScoreboardCommand(Game& game_) : Command(game_) {}

	void execute(const std::vector<std::string>& args) override;
};

