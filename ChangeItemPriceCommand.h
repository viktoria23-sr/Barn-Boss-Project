#pragma once
#include "Command.h"
#include <print>

class ChangeItemPriceCommand final : public Command
{
public:
	ChangeItemPriceCommand(Game& game_) : Command(game_) {}

	void execute(const std::vector<std::string>& args) override;
};



