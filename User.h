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
	bool isAccuratePassword(const std::string& password) const;
	void logout();
	void changePassword(const std::string& oldPassword, const std::string& newPassword);
	virtual void profileInfo() const; //=0 ???

	std::string getId() const;
	std::string getUsername() const;
};

