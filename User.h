#pragma once
#include <string>
#include <print>

class User
{
protected:
	std::string id;
	std::string username;
	std::string password;

public:
	bool isAccuratePassword(std::string password) const;
	void logout();
	void changePassword(std::string oldPassword, std::string newPassword);
	virtual void profileInfo() const; //=0 ???

	std::string getId() const;
	std::string getUsername() const;
};

