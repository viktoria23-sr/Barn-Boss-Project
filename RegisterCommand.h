#pragma once
#include "Command.h"
#include <print>

class RegisterCommand final : public Command
{
public:
	RegisterCommand(Game& game_) : Command(game_) {}

	void execute(const std::vector<std::string>& args) override;
};

