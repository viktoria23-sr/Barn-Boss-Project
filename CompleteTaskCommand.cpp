#include "CompleteTaskCommand.h"
#include "Game.h"
#include "Player.h"

void CompleteTaskCommand::execute(const std::vector<std::string>& args)
{
    User* currentUser = game.getCurrentUser();

    if (currentUser == nullptr)
    {
        std::println("Error: You must be logged in to complete tasks!");
        return;
    }

    if (currentUser->getRole() != "Player")
    {
        std::println("Error: Only players can complete tasks and claim rewards!");
        return;
    }

    if (args.empty())
    {
        std::println("Error: Invalid format!");
        std::println("Expected: completeTask <task_id>");
        return;
    }

    size_t taskId = 0;

    try
    {
        taskId = std::stoull(args[0]);
    }
    catch (const std::exception&)
    {
        std::println("Error: Invalid task ID! Please enter a valid number.");
        return;
    }

    Player* player = static_cast<Player*>(currentUser);
    player->completeTask(taskId);
}
