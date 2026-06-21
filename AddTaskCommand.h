#pragma once
#include "Command.h"
#include <print>

class AddTaskCommand final : public Command
{
public:
	AddTaskCommand(Game& game_) : Command(game_) {}

	void execute(const std::vector<std::string>& args) override;
};

