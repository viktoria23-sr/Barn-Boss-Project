#pragma once
#include "Command.h"
#include <print>

class ShowTaskboardCommand final : public Command
{
public:
	ShowTaskboardCommand(Game& game_) : Command(game_) {}

	void execute(const std::vector<std::string>& args) override;
};

