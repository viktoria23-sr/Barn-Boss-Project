#pragma once
#include <vector>
#include "Task.h"

class TaskBoard
{
protected:
	std::vector<Task> tasks;
	static int uncompletedTasks;

public:
	TaskBoard();
};
