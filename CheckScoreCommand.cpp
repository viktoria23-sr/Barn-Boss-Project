#include "CheckScoreCommand.h"
#include "Game.h"
#include "Player.h"

void CheckScoreCommand::execute(const std::vector<std::string>& args)
{
    User* currentUser = game.getCurrentUser();

    if (currentUser == nullptr)
    {
        std::println("Error: You must be logged in to check your score!");
        return;
    }

    if (currentUser->getRole() != "Player")
    {
        std::println("Error: Only players have a bank score!");
        return;
    }

    if (!args.empty())
    {
        std::println("Error: Invalid format!");
        std::println("Expected: checkScore");
        return;
    }

    Player* player = static_cast<Player*>(currentUser);

    double currentScore = player->checkScore();

    std::println("Your current balance is: {} gold.", currentScore);
}
