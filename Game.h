#pragma once
#include <fstream>
#include <vector>
#include <stdexcept>
#include <memory>
#include <unordered_map>
#include "User.h"
#include "Player.h"
#include "TaskManager.h"
#include "MarketManager.h"
#include "UserFactory.h"
#include "ScoreBoard.h"
#include "Command.h"

class Game
{
private:
    std::vector<std::unique_ptr<User>> users;
    std::unordered_map<std::string, std::unique_ptr<Command>> commands;
    User* currentUser = nullptr;
    bool isRunning = true;

    bool existsUsername(const std::string& username) const;
    bool existsId(const std::string& id) const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

public:
    Game() = default;

    void start();
    void stop();

    void setupCommands();
    User* getCurrentUser();
    void executeRegister(const std::string& role, const std::string& username, const std::string& password);
    void executeLogin(const std::string& username, const std::string& password);
    void executeLogout();
    void showScoreboard() const;
};

