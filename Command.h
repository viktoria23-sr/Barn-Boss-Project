#pragma once
#include <vector>
#include <string>

class Game;

class Command
{
protected:
    Game& game;

public:
    Command(Game& game_) : game(game_) {}
    virtual ~Command() = default;
    virtual void execute(const std::vector<std::string>& args) = 0;
};

