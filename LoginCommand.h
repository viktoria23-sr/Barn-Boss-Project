#pragma once
#include "Command.h"
#include <print>

class LoginCommand final : public Command
{
public:
	LoginCommand(Game& game_) : Command(game_) {}

	void execute(const std::vector<std::string>& args) override;
};

