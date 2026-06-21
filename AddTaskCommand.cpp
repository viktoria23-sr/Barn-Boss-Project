#include "AddTaskCommand.h"
#include "Game.h"
#include "TaskManager.h"

void AddTaskCommand::execute(const std::vector<std::string>& args)
{
    User* currentUser = game.getCurrentUser();

    if (currentUser == nullptr)
    {
        std::println("Error: You must be logged in to add tasks!");
        return;
    }

    if (currentUser->getRole() != "TaskManager")
    {
        std::println("Error: Only the Task Manager can create tasks!");
        return;
    }

    if (args.size() < 4)
    {
        std::println("Error: Invalid format!");
        std::println("Expected: addTask <product_id> <quantity> <reward_money> <reward_score>");
        return;
    }

    PossibleProducts requiredProduct;
    unsigned quantity = 0;
    size_t rewardBalance = 0;
    size_t rewardScore = 0;

    try
    {
        size_t productId = std::stoull(args[0]);
        requiredProduct = getProductType(productId);

        int tempQty = std::stoi(args[1]);
        int tempMoney = std::stoi(args[2]);
        int tempScore = std::stoi(args[3]);

        if (tempQty <= 0 || tempQty > 10000 || tempMoney <= 0 || 
            tempMoney > 10000 || tempScore <= 0 || tempScore > 10000)
        {
            std::println("Error: Quantity, money, and score must be positive numbers between 1 and 10000!");
            return;
        }

        quantity = static_cast<unsigned>(tempQty);
        rewardBalance = static_cast<size_t>(tempMoney);
        rewardScore = static_cast<size_t>(tempScore);
    }
    catch (const std::exception&)
    {
        std::println("Error: Invalid arguments! Please enter valid integers.");
        return;
    }

    TaskManager* tManager = static_cast<TaskManager*>(currentUser);
    tManager->addTask(requiredProduct, quantity, rewardBalance, rewardScore);
}
