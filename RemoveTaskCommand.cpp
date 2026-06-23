#include "RemoveTaskCommand.h"
#include "Game.h"
#include "TaskManager.h"

void RemoveTaskCommand::execute(const std::vector<std::string>& args)
{
    User* currentUser = game.getCurrentUser();

    if (currentUser == nullptr)
    {
        std::println("Error: You must be logged in to remove tasks!");
        return;
    }

    if (currentUser->getRole() != "TaskManager")
    {
        std::println("Error: Only the Task Manager can remove tasks!");
        return;
    }

    if (args.empty())
    {
        std::println("Error: Invalid format!");
        std::println("Expected: removeTask <task_id>");
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

    TaskManager* manager = static_cast<TaskManager*>(currentUser);
    manager->removeTask(taskId);
}

