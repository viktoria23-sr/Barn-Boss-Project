#pragma once
#include "Command.h"
#include <print>

class ProfileInfoCommand final : public Command
{
public:
	ProfileInfoCommand(Game& game_) : Command(game_) {}

	void execute(const std::vector<std::string>& args) override;
};

