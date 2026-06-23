#include "Game.h"
#include "Command.h"
#include "AddAnimalCommand.h"
#include "AddTaskCommand.h"
#include "BuyItemCommand.h"
#include "ChangeItemPriceCommand.h"
#include "ChangePasswordCommand.h"
#include "CheckBalanceCommand.h"
#include "CheckScoreCommand.h"
#include "CompleteTaskCommand.h"
#include "ExitCommand.h"
#include "ExpandCroplandCommand.h"
#include "ExpandFarmlandCommand.h"
#include "HarvestCommand.h"
#include "LoginCommand.h"
#include "LogoutCommand.h"
#include "PrintBarnCommand.h"
#include "PrintFarmCommand.h"
#include "PrintMarketCommand.h"
#include "ProfileInfoCommand.h"
#include "RegisterCommand.h"
#include "RestockCommand.h"
#include "RemoveTaskCommand.h"
#include "SellItemCommand.h"
#include "ShowScoreboardCommand.h"
#include "ShowTaskboardCommand.h"
#include "SowPlantCommand.h"

bool Game::existsUsername(const std::string& username) const
{
    for (const auto& user : users)
    {
        if (user -> getUsername() == username)
        {
            return true;
        }
    }

    return false;
}

bool Game::existsId(const std::string& id) const
{
    for (const auto& user : users)
    {
        if (user->getId() == id)
        {
            return true;
        }
    }

    return false;
}

void Game::saveToFile(const std::string& filename) const
{
    std::ofstream outFile(filename);

    if (!outFile.is_open())
    {
        std::println("Error: Could not open file '{}' for saving data!", filename);
        return;
    }

    outFile << users.size() << "\n";

    for (const auto& userPtr : users)
    {
        outFile << userPtr->getRole() << " ";
        userPtr->save(outFile);
        outFile << "\n";
    }

    std::println("Game data successfully saved to '{}'.", filename);
    outFile.close();
}

void Game::loadFromFile(const std::string& filename)
{
    std::ifstream inFile(filename);

    if (!inFile.is_open())
    {
        std::println("No saved file found. Starting a new game!");
        return;
    }

    users.clear();
    currentUser = nullptr;

    size_t userCount = 0;
    if (!(inFile >> userCount))
    {
        return; 
    }

    for (size_t i = 0; i < userCount; ++i)
    {
        std::string role, id, username, password;
        if (!(inFile >> role >> id >> username >> password)) break;

        auto newUser = UserFactory::create(role, id, username, password);

        if (newUser)
        {
            newUser->load(inFile);

            users.push_back(std::move(newUser));
        }
    }
    inFile.close();
}

void Game::start()
{
    std::string filename = "BarnBoss.txt";

    std::println("=== Welcome to Barn Boss ===");

     std::ifstream checkFile(filename);
     char dummyChar;

     if (checkFile.is_open() && checkFile.get(dummyChar))
     {
         std::println("A saved game was found. What would you like to do?");
         std::println("1. Continue (Load Game)");
         std::println("2. Start New Game");
         std::print("> ");

         std::string choice;
         std::getline(std::cin, choice);

         if (choice == "1")
         {
             checkFile.close();
             loadFromFile(filename);
             std::println("Game loaded successfully!");
         }
         else
         {
             checkFile.close();
             std::println("Starting a fresh new game...");
         }
     }

     else
     {
         checkFile.close();
         std::println("No saved game found. Starting a fresh new game...");
     }

    setupCommands();

    std::string firstWord;

    while (this->isRunning)
    {
        std::print("> ");
        if (!(std::cin >> firstWord))
        {
            break;
        }

        auto it = commands.find(firstWord);
        if (it != commands.end())
        {
            std::vector<std::string> args;
            std::string arg;

            while (std::cin.peek() != '\n' && std::cin >> arg)
            {
                args.push_back(arg);
            }

            it->second->execute(args);
        }
        else
        {
            std::println("Unknown command: '{}'", firstWord);

            std::cin.clear();
            std::string ignoreLine;
            std::getline(std::cin, ignoreLine);
        }
    }

    saveToFile("BarnBoss.txt");
}

void Game::stop()
{
    isRunning = false;
}

void Game::setupCommands()
{
    commands["register"] = std::make_unique<RegisterCommand>(*this);
    commands["exit"] = std::make_unique<ExitCommand>(*this);
    commands["login"] = std::make_unique<LoginCommand>(*this);
    commands["logout"] = std::make_unique<LogoutCommand>(*this);
    commands["printBarn"] = std::make_unique<PrintBarnCommand>(*this);
    commands["printFarm"] = std::make_unique<PrintFarmCommand>(*this);
    commands["changePassword"] = std::make_unique<ChangePasswordCommand>(*this);
    commands["sowPlant"] = std::make_unique<SowPlantCommand>(*this);
    commands["addAnimal"] = std::make_unique<AddAnimalCommand>(*this);
    commands["profileInfo"] = std::make_unique<ProfileInfoCommand>(*this);
    commands["harvest"] = std::make_unique<HarvestCommand>(*this);
    commands["checkBalance"] = std::make_unique<CheckBalanceCommand>(*this);
    commands["checkScore"] = std::make_unique<CheckScoreCommand>(*this);
    commands["buyItem"] = std::make_unique<BuyItemCommand>(*this);
    commands["sellItem"] = std::make_unique<SellItemCommand>(*this);
    commands["showTaskBoard"] = std::make_unique<ShowTaskboardCommand>(*this);
    commands["addTask"] = std::make_unique<AddTaskCommand>(*this);
    commands["removeTask"] = std::make_unique<RemoveTaskCommand>(*this);
    commands["expandCropland"] = std::make_unique<ExpandCroplandCommand>(*this); 
    commands["expandFarmland"] = std::make_unique<ExpandFarmlandCommand>(*this); 
    commands["printMarket"] = std::make_unique<PrintMarketCommand>(*this);
    commands["completeTask"] = std::make_unique<CompleteTaskCommand>(*this);
    commands["showScoreboard"] = std::make_unique<ShowScoreboardCommand>(*this);
    commands["changePrice"] = std::make_unique<ChangeItemPriceCommand>(*this);
    commands["restock"] = std::make_unique<RestockCommand>(*this);
}

User* Game::getCurrentUser()
{
    return currentUser;
}

void Game::executeRegister(const std::string& role, const std::string& username, const std::string& password)
{
    if (existsUsername(username))
    {
        std::println("Error: A User with the username '{}' already exists!", username);
        return;
    }

    std::string generatedId = "";
    if (role == "Player")
    {
        generatedId = "P_" + std::to_string(users.size() + 1);
    }
    else if (role == "TaskManager")
    {
        generatedId = "T_MANAGER";
    }
    else if (role == "MarketManager")
    {
        generatedId = "M_MANAGER";
    }

    try
    {
        auto newUser = UserFactory::create(role, generatedId, username, password);

        if (newUser)
        {
            users.push_back(std::move(newUser));
            std::println("{} registered successfully!", role);
        }
        else
        {
            std::println("Error: Unknown or invalid user role '{}'!", role);
        }
    }
    catch (const std::runtime_error& e)
    {
        std::println("{}", e.what());
    }
}

void Game::executeLogin(const std::string& username, const std::string& password)
{
    if (currentUser != nullptr)
    {
        std::println("Error: Someone is already logged in! Log out first.");
        return;
    }

    for (const auto& userPtr : users)
    {
        if (userPtr->getUsername() == username)
        {
            if (userPtr->getPassword() == password)
            { 
                currentUser = userPtr.get();
                std::println("Welcome, {}!", username);

                std::println("Available commands for your role ({}):", currentUser->getRole()); //

                std::println(" - logout");
                std::println(" - changePassword");
                std::println(" - profileInfo");
                std::println(" - exit");

                if (currentUser->getRole() == "Player")
                {
                    std::println(" - printBarn");
                    std::println(" - sowPlant");
                    std::println(" - addAnimal");
                    std::println(" - harvest");
                    std::println(" - checkBalance");
                    std::println(" - checkScore");
                    std::println(" - buyItem");
                    std::println(" - sellItem");
                    std::println(" - showTaskBoard");
                    std::println(" - completeTask");
                    std::println(" - expandCropland");
                    std::println(" - expandFarmland");
                    std::println(" - printMarket");
                    std::println(" - showScoreboard");
                }
                else if (currentUser->getRole() == "TaskManager")
                {
                    std::println(" - addTask");
                    std::println(" - removeTask");
                    std::println(" - showTaskBoard");
                }

                else if (currentUser->getRole() == "MarketManager")
                {
                    std::println(" - changeItemPrice");
                    std::println(" - restock");
                }

                std::println("====================");

                return;
            }
            
            std::println("Error: Invalid password!");
            return;
        }
    }

    std::println("Error: User '{}' does not exist!", username);
}

void Game::executeLogout()
{
    if (this->currentUser == nullptr)
    {
        std::println("Error: You are not logged in!");
        return;
    }

    std::string username = currentUser->getUsername();
    currentUser = nullptr;

    std::println("User '{}' logged out successfully.", username);
}

void Game::showScoreboard() const
{
     std::vector<const Player*> playersOnly;

    for (const auto& userPtr : users)
    {
        if (userPtr->getRole() == "Player")
        {
            const Player* playerPtr = static_cast<const Player*>(userPtr.get());
            playersOnly.push_back(playerPtr);
        }
    }

    ScoreBoard sb;
    sb.showScoreBoard(playersOnly);
}
