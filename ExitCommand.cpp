#include "ExitCommand.h"
#include "Game.h"

void ExitCommand::execute(const std::vector<std::string>& args)
{
    std::println("Saving data and exiting game...");
    game.stop();
}
