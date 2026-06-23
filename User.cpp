#include "User.h"

User::User(const std::string& id_, const std::string& username_, const std::string& password_) :
    id(id_), username(username_), password(password_) { }

bool User::isAccuratePassword(const std::string& password_) const
{
    if (password_.length() < MIN_PASSWORD_LENGTH)
    {
        return false;
    }

    return true;
}

void User::logout()
{
    std::println("User '{}' is logging out...", username);
}

void User::changePassword(const std::string& oldPassword, const std::string& newPassword)
{
    if (password != oldPassword)
    {
        std::println("Error: Incorrect old password!");
        return;
    }

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

const std::string& User::getPassword() const
{
    return password;
}

void User::save(std::ostream& out) const
{
    out << id << " " << username << " " << password;
}
