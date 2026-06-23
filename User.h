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
	User(const std::string& id_, const std::string& username_, const std::string& password_);
	
	bool isAccuratePassword(const std::string& password) const;
	void logout();
	void changePassword(const std::string& oldPassword, const std::string& newPassword);
	virtual void profileInfo() const = 0;
	virtual ~User() = default;

	const std::string& getId() const;
	const std::string& getUsername() const;
	const std::string& getPassword() const;

	virtual void save(std::ostream& out) const;
	virtual void load(std::istream& in) {}
	virtual std::string getRole() const = 0;
};

