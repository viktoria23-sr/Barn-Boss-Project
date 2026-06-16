#pragma once
#include "User.h"
#include "TaskBoard.h"

class TaskManager : public User
{
private:

	static bool hasInstance;

public:
	TaskManager() = default;
	TaskManager(const std::string& username_, const std::string& password_);
	~TaskManager();

	void showTasks();
	void addTask(PossibleProducts requiredProduct, unsigned quantity, size_t rewardBalance, size_t rewardScore);
	void removeTask(size_t taskId);
	void profileInfo() const override;
	std::string getRole() const override;
};

