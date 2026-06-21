#include "AddAnimalCommand.h"
#include "Game.h"
#include "Player.h"

void AddAnimalCommand::execute(const std::vector<std::string>& args)
{
    User* currentUser = game.getCurrentUser();

    if (currentUser == nullptr)
    {
        std::println("Error: You must be logged in to add animals!");
        return;
    }

    if (currentUser->getRole() != "Player")
    {
        std::println("Error: Only players can add animals to a farm!");
        return;
    }


    if (args.empty())
    {
        std::println("Error: Invalid format!");
        std::println("Expected: addAnimal <animal_id>");
        return;
    }

    size_t animalId = 0;

    try
    {
        animalId = std::stoull(args[0]);
    }
    catch (const std::exception&)
    {
        std::println("Error: Invalid animal ID! Please enter a valid number.");
        return;
    }

    Player* player = static_cast<Player*>(currentUser);
    player->addAnimal(animalId);
}
