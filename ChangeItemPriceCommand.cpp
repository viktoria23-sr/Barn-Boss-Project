#include "ChangeItemPriceCommand.h"
#include "Game.h"
#include "MarketManager.h"
#include <stdexcept>

void ChangeItemPriceCommand::execute(const std::vector<std::string>& args)
{
    User* currentUser = game.getCurrentUser();

    if (currentUser == nullptr)
    {
        std::println("Error: You must be logged in to change item prices!");
        return;
    }

    if (currentUser->getRole() != "MarketManager")
    {
        std::println("Error: Only the Market Manager can change product prices!");
        return;
    }

    if (args.size() < 2)
    {
        std::println("Error: Invalid format!");
        std::println("Expected: changePrice <product_id> <new_price>");
        return;
    }

    size_t productId = 0;
    unsigned newPrice = 0;

    try
    {
        productId = std::stoull(args[0]);

        int tempPrice = std::stoi(args[1]);
        if (tempPrice < 0)
        {
            std::println("Error: Price cannot be negative!");
            return;
        }
        newPrice = static_cast<unsigned>(tempPrice);
    }
    catch (const std::exception&)
    {
        std::println("Error: Invalid arguments! Please enter valid integers.");
        return;
    }

    MarketManager* manager = static_cast<MarketManager*>(currentUser);

    try
    {
        manager->changePrice(productId, newPrice); //
    }
    catch (const std::invalid_argument& e)
    {
        std::println("{}", e.what());
    }
}
