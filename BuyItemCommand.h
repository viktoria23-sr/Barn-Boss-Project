#pragma once
#include "Command.h"
#include <print>

class BuyItemCommand final : public Command
{
public:
	BuyItemCommand(Game& game_) : Command(game_) {}

	void execute(const std::vector<std::string>& args) override;
};

