#include "LogoutCommand.h"
#include "Game.h"
#include "User.h"

void LogoutCommand::execute(const std::vector<std::string>& args)
{
    if (!args.empty())
    {
        std::println("Error: Invalid format! Expected: logout");
        return;
    }

    game.executeLogout();
}
