#include "ChangePasswordCommand.h"
#include "Game.h"
#include "User.h"

void ChangePasswordCommand::execute(const std::vector<std::string>& args)
{
    User* currentUser = game.getCurrentUser();

    if (currentUser == nullptr)
    {
        std::println("Error: You must be logged in to change your password!");
        return;
    }

    if (args.size() < 2)
    {
        std::println("Error: Invalid format!");
        std::println("Expected: changePassword <old_password> <new_password>");
        return;
    }

    currentUser->changePassword(args[0], args[1]);
}
