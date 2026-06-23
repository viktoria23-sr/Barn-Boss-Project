#include "PrintFarmCommand.h"
#include "Game.h"
#include "Player.h"

void PrintFarmCommand::execute(const std::vector<std::string>& args)
{
    User* currentUser = game.getCurrentUser();

    if (currentUser == nullptr)
    {
        std::println("Error: You must be logged in to view your farm!");
        return;
    }

    if (currentUser->getRole() != "Player")
    {
        std::println("Error: Only players can have a farm!");
        return;
    }

    if (!args.empty())
    {
        std::println("Error: Invalid format! Expected: printFarm");
        return;
    }

    Player* player = static_cast<Player*>(currentUser);
    player->checkFarm();
}

