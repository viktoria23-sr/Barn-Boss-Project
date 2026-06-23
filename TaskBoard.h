#pragma once
#include <map>
#include "Task.h"
#include <print>

class TaskBoard
{
protected:
	std::vector<Task> tasks;
	TaskBoard();

public:
	const std::map<size_t, Task>& getTasks() const;

	TaskBoard(const TaskBoard& other) = delete;
	TaskBoard& operator=(const TaskBoard& other) = delete;

	static TaskBoard& getInstance();
	void addTask(const Task& newTask);
	void removeTaskById(size_t taskId);
	Task* findTaskById(size_t taskId);
};
