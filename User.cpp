#include "User.h"

bool User::isAccuratePassword(const std::string& password_) const
{
    if (password_ == "   " || password_.length() < 3)
    {
        return false;
    }

    return true;
}

void User::changePassword(const std::string& oldPassword, const std::string& newPassword)
{
    if (isAccuratePassword(newPassword))
    {
        if (oldPassword == newPassword)
        {
            std::println("The new password is the same as the old. Choose another one!");
            return;
        }
    
        password = newPassword;
    }
}

void User::profileInfo() const
{
    std:print("Id: {}, Username: {}, Password: {}", id, username, password);
}

const std::string& User::getId() const
{
    return id;
}

const std::string& User::getUsername() const
{
    return username;
}
