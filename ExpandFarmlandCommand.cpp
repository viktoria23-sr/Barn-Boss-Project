#include "ExpandFarmlandCommand.h"
#include "Game.h"
#include "Player.h"

void ExpandFarmlandCommand::execute(const std::vector<std::string>& args)
{
    User* currentUser = game.getCurrentUser();

    if (currentUser == nullptr)
    {
        std::println("Error: You must be logged in to expand your farmland!");
        return;
    }

    if (currentUser->getRole() != "Player")
    {
        std::println("Error: Only players can expand their farmland capacity!");
        return;
    }

    if (!args.empty())
    {
        std::println("Error: Invalid format! Expected: expandFarmland");
        return;
    }

    Player* player = static_cast<Player*>(currentUser);
    player->expandFarmland();

}
