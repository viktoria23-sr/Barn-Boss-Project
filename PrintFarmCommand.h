#pragma once
#include "Command.h"
#include <print>

class PrintFarmCommand final : public Command
{
public:
    PrintFarmCommand(Game& game_) : Command(game_) {}

    void execute(const std::vector<std::string>& args) override;
};