#include "LoginCommand.h"
#include "Game.h"

void LoginCommand::execute(const std::vector<std::string>& args)
{
    if (args.size() < 2)
    {
        std::println("Error: Invalid login format!");
        std::println("Expected input: login <username> <password>");
        return;
    }

    std::string username = args[0];
    std::string password = args[1];

    game.executeLogin(username, password);
}
