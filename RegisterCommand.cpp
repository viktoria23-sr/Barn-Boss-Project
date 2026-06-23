#include "RegisterCommand.h"
#include "Game.h"

void RegisterCommand::execute(const std::vector<std::string>& args)
{
    if (args.size() < 3)
    {
        std::println("Error: Invalid register format!");
        std::println("Expected input: register <username> <password> <role>");
        return;
    }

    std::string username = args[0];
    std::string password = args[1];
    std::string role = args[2];

    if (!User::isAccuratePassword(password))
    {
         std::println("Error: Password is too short!");
         return;
    }
    
    game.executeRegister(role, username, password);
}
