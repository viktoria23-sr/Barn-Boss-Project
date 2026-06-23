#pragma once
#include "Command.h"
#include <print>

class RemoveTaskCommand final : public Command
{
public:
	RemoveTaskCommand(Game& game_) : Command(game_) {}

	void execute(const std::vector<std::string>& args) override;
};

