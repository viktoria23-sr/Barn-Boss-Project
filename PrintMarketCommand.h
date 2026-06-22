#pragma once
#include "Command.h"
#include <print>

class PrintMarketCommand final : public Command
{
public:
	PrintMarketCommand(Game& game_) : Command(game_) {}

	void execute(const std::vector<std::string>& args) override;
};

