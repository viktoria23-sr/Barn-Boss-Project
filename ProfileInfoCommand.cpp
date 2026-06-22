#include "ProfileInfoCommand.h"
#include "Game.h"
#include "User.h"

void ProfileInfoCommand::execute(const std::vector<std::string>& args)
{
    User* currentUser = game.getCurrentUser();

    if (currentUser == nullptr)
    {
        std::println("Error: You must be logged in to view your profile info!");
        return;
    }

    currentUser->profileInfo();
}
