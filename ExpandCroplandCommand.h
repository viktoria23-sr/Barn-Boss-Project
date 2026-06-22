#pragma once
#include "Command.h"
#include <print>

class ExpandCroplandCommand final : public Command
{
public:
	ExpandCroplandCommand(Game& game_) : Command(game_) {}

	void execute(const std::vector<std::string>& args) override;
};

