#include "PrintMarketCommand.h"
#include "Game.h"

void PrintMarketCommand::execute(const std::vector<std::string>& args)
{
    User* currentUser = game.getCurrentUser();

    if (currentUser == nullptr)
    {
        std::println("Error: You must be logged in to view the market catalog!");
        return;
    }

    if (currentUser->getRole() != "Player")
    {
        std::println("Error: Only players can open the market catalog!");
        return;
    }

    if (!args.empty())
    {
        std::println("Error: Invalid format! Expected: printMarket");
        return;
    }

    Player* player = static_cast<Player*>(currentUser);
    player->openMarketCatalog();
}
