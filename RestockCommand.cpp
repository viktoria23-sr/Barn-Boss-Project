#include "RestockCommand.h"
#include "Game.h"
#include "MarketManager.h"

void RestockCommand::execute(const std::vector<std::string>& args)
{
    User* currentUser = game.getCurrentUser();

    if (currentUser == nullptr)
    {
        std::println("Error: You must be logged in to restock the market!");
        return;
    }

    if (currentUser->getRole() != "MarketManager")
    {
        std::println("Error: Only the Market Manager can restock products!");
        return;
    }

    if (args.size() < 2)
    {
        std::println("Error: Invalid format!");
        std::println("Expected: restock <product_id> <quantity>");
        return;
    }

    size_t productId = 0;
    unsigned quantity = 0;

    try
    {
        productId = std::stoull(args[0]);

        int tempQuantity = std::stoi(args[1]);
        if (tempQuantity <= 0)
        {
            std::println("Error: Quantity must be a positive number!");
            return;
        }
        quantity = static_cast<unsigned>(tempQuantity);
    }
    catch (const std::exception&)
    {
        std::println("Error: Invalid arguments! Please enter valid integers.");
        return;
    }

    MarketManager* manager = static_cast<MarketManager*>(currentUser);

    try
    {
        manager->restock(productId, quantity);
    }
    catch (const std::invalid_argument& e)
    {
        std::println("{}", e.what());
    }
}
