#pragma once
#include "Command.h"
#include <print>

class CompleteTaskCommand final : public Command
{
public:
	CompleteTaskCommand(Game& game_) : Command(game_) {}

	void execute(const std::vector<std::string>& args) override;
};

