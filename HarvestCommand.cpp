#include "HarvestCommand.h"
#include "Game.h"
#include "Player.h"

void HarvestCommand::execute(const std::vector<std::string>& args)
{
    User* currentUser = game.getCurrentUser();

    if (currentUser == nullptr)
    {
        std::println("Error: You must be logged in to harvest!");
        return;
    }

    if (currentUser->getRole() != "Player")
    {
        std::println("Error: Only players can harvest!");
        return;
    }

    if (!args.empty())
    {
        std::println("Error: Invalid format!");
        std::println("Expected: harvest");
        return;
    }

    Player* player = static_cast<Player*>(currentUser);
    player->harvest();

    std::println("Harvest cycle completed!");
}
