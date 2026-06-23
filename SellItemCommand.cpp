#include "SellItemCommand.h"
#include "Game.h"
#include "Player.h"

void SellItemCommand::execute(const std::vector<std::string>& args)
{
    User* currentUser = game.getCurrentUser();

    if (currentUser == nullptr)
    {
        std::println("Error: You must be logged in to sell items!");
        return;
    }

    if (currentUser->getRole() != "Player")
    {
        std::println("Error: Only players can sell items to the market!");
        return;
    }

    if (args.size() < 2)
    {
        std::println("Error: Invalid format!");
        std::println("Expected: sellItem <product_id> <quantity>");
        return;
    }

    size_t productId = 0;
    unsigned quantity = 0;

    try
    {
        productId = std::stoull(args[0]);

        int tempQuantity = std::stoi(args[1]);
        if (tempQuantity <= 0 || tempQuantity > 10000)
        {
            std::println("Error: Quantity must be between 1 and 10000!");
            return;
        }

        quantity = static_cast<unsigned>(tempQuantity);
    }
    catch (const std::exception&)
    {
        std::println("Error: Invalid arguments! Please enter a valid number for ID and quantity (max 10000).");
        return;
    }

    Player* player = static_cast<Player*>(currentUser);
    player->sellItem(productId, quantity); 
}
