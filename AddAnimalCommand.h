#pragma once
#include "Command.h"
#include <print>

class AddAnimalCommand final : public Command
{
public:
	AddAnimalCommand(Game& game_) : Command(game_) {}

	void execute(const std::vector<std::string>& args) override;
};

