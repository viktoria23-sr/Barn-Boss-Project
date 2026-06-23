#include "ShowTaskboardCommand.h"
#include "Game.h"
#include "User.h"

void ShowTaskboardCommand::execute(const std::vector<std::string>& args)
{
    User* currentUser = game.getCurrentUser();

    if (currentUser == nullptr)
    {
        std::println("Error: You must be logged in to view the taskboard!");
        return;
    }

    if (!args.empty())
    {
        std::println("Error: Invalid format! Expected: showTaskboard");
        return;
    }

    TaskBoard& taskBoard = TaskBoard::getInstance();

    if (taskBoard.getTasks().empty())
    {
        std::println("There are no unfinished tasks.");
        return;
    }

    for (const auto& [id, task] : taskBoard.getTasks())
    {
        std::println("TaskId: {}, RequiredProductType: {}, RequiredQuantity: {}, RewardBalance: {}, RewardScore: {}",
            task.getId(), toString(task.getRequiredProduct()), task.getRequiredQuantity(), task.getRewardBalance(), task.getRewardScore());
    }
}
