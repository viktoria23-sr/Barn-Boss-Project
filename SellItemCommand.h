#pragma once
#include "Command.h"
#include <print>

class SellItemCommand final : public Command
{
public:
	SellItemCommand(Game& game_) : Command(game_) {}

	void execute(const std::vector<std::string>& args) override;
};

