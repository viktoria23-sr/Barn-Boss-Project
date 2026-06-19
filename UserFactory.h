#pragma once
#include "User.h"
#include "Player.h"
#include "TaskManager.h"
#include "MarketManager.h"

class UserFactory
{
public:

    static std::unique_ptr<User> create(const std::string& role,
        const std::string& id,
        const std::string& username,
        const std::string& password)
    {
        if (role == "Player") return std::make_unique<Player>(id, username, password, 100.0, 0);
        if (role == "TaskManager") return std::make_unique <TaskManager>(username, password);
        if (role == "MarketManager") return std::make_unique<MarketManager>(username, password);

        return nullptr;
    }
};

