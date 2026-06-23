#include "TaskManager.h"
#include "Market.h"

bool TaskManager::hasInstance = false;

TaskManager::TaskManager(const std::string& username_, const std::string& password_) : 
    User("TaskManager", username_, password_)
{
    if (hasInstance)
    {
        throw std::runtime_error("Registration failed: A Task Manager already exists in the system!");
    }
    
    hasInstance = true;
}

TaskManager::~TaskManager()
{
    hasInstance = false;
}

void TaskManager::showTasks()
{
    TaskBoard& taskBoard = TaskBoard::getInstance();

    std::println("=======   TASK BOARD   =======");
    const auto& currentTasks = taskBoard.getTasks();

    if(currentTasks.empty())
    {
        std::println("No active tasks available.");
        return;
    }

    for (const auto& [id, task] : currentTasks)
    {
        std::println("{}. Deliver {} {} -> Reward: {} Balance, {} Score",
            task.getId(),
            task.getRequiredQuantity(),
            toString(task.getRequiredProduct()),
            task.getRewardBalance(),
            task.getRewardScore());
    }
}

void TaskManager::addTask(PossibleProducts requiredProduct, unsigned quantity, size_t rewardBalance, size_t rewardScore)
{
    TaskBoard& taskBoard = TaskBoard::getInstance();
    const auto& tasks = taskBoard.getTasks();

    size_t newId = 1;

    if (!tasks.empty())
    {
        newId = tasks.rbegin()->first + 1;
    }
    Task newTask(newId, requiredProduct, quantity, rewardBalance, rewardScore);
    taskBoard.addTask(newTask);

    std::println("Task added successfully!");
}

void TaskManager::removeTask(size_t taskId)
{
    TaskBoard& taskBoard = TaskBoard::getInstance();

    try
    {
        taskBoard.removeTaskById(taskId);
        std::println("Task with ID {} removed successfully!", taskId);
    }
    catch (const std::invalid_argument& e)
    {
        std::println("Task with ID {} not found.", taskId);
    }

}

void TaskManager::profileInfo() const
{
    std::println("=== TASK MANAGER PROFILE ===");
    std::println("ID: {}", id);
    std::println("Username: {}", username);
    std::println("Type: TaskManager");
}

std::string TaskManager::getRole() const
{
    return "TaskManager";
}
