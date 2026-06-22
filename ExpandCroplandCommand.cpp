#include "ExpandCroplandCommand.h"
#include "Game.h"
#include "Player.h"

void ExpandCroplandCommand::execute(const std::vector<std::string>& args)
{
    User* currentUser = game.getCurrentUser();

    if (currentUser == nullptr)
    {
        std::println("Error: You must be logged in to expand your cropland!");
        return;
    }

    if (currentUser->getRole() != "Player")
    {
        std::println("Error: Only players can expand their cropland capacity!");
        return;
    }

    if (!args.empty())
    {
        std::println("Error: Invalid format! Expected: expandCropland");
        return;
    }

    Player* player = static_cast<Player*>(currentUser);
    player->expandCropland();
}