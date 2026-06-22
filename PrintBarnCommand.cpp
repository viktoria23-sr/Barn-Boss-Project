#include "PrintBarnCommand.h"
#include "Game.h"
#include "Player.h"

void PrintBarnCommand::execute(const std::vector<std::string>& args)
{
    User* currentUser = game.getCurrentUser();

    if (currentUser == nullptr)
    {
        std::println("Error: You must be logged in to view your barn!");
        return;
    }

    if (currentUser->getRole() != "Player")
    {
        std::println("Error: Only players have a barn!");
        return;
    }

    Player* player = static_cast<Player*>(currentUser);
    player->checkBarn();
}
