#include "CheckBalanceCommand.h"
#include "Game.h"
#include "Player.h"

void CheckBalanceCommand::execute(const std::vector<std::string>& args)
{
    User* currentUser = game.getCurrentUser();

    if (currentUser == nullptr)
    {
        std::println("Error: You must be logged in to check your balance!");
        return;
    }

    if (currentUser->getRole() != "Player")
    {
        std::println("Error: Only players have a bank balance!");
        return;
    }

    if (!args.empty())
    {
        std::println("Error: Invalid format!");
        std::println("Expected: checkBalance");
        return;
    }

    Player* player = static_cast<Player*>(currentUser);

    double currentBalance = player->checkBalance();

    std::println("Your current balance is: {} money.", currentBalance);
}
