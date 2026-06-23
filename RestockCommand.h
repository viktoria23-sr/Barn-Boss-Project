#pragma once
#include "Command.h"
#include <print>

class RestockCommand final : public Command
{
public:
	RestockCommand(Game& game_) : Command(game_) {}

	void execute(const std::vector<std::string>& args) override;
};

