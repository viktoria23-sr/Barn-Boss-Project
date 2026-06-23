#include "SowPlantCommand.h"
#include "Game.h"
#include "Player.h"

void SowPlantCommand::execute(const std::vector<std::string>& args)
{
    User* currentUser = game.getCurrentUser();

    if (currentUser == nullptr)
    {
        std::println("Error: You must be logged in to sow plants!");
        return;
    }

    if (currentUser->getRole() != "Player")
    {
        std::println("Error: Only players can sow plants!");
        return;
    }

    if (args.empty())
    {
        std::println("Error: Invalid format!");
        std::println("Expected: sowPlant <seed_id>");
        return;
    }

    size_t seedId = 0;

    try
    {
        seedId = std::stoull(args[0]);
    }
    catch (const std::exception&)
    {
        std::println("Error: Invalid seed ID! Please enter a valid number.");
        return;
    }

    Player* player = static_cast<Player*>(currentUser);
    player->sowPlant(seedId);
}
