#include "TaskBoard.h"

TaskBoard::TaskBoard()
{
	tasks.insert({ 1, Task(1, PossibleProducts::Wheat, 5, 50, 10) });
	tasks.insert({ 2, Task(2, PossibleProducts::Milk, 3, 120, 20) });
}

TaskBoard& TaskBoard::getInstance()
{
	static TaskBoard instance;
	return instance;
}

const std::map<size_t, Task>& TaskBoard::getTasks() const
{
	return tasks;
}

void TaskBoard::removeTaskById(size_t taskId)
{
	if (tasks.erase(taskId) == 0)
	{
		throw std::invalid_argument("There is no task with such an ID!");
	}
}

Task* TaskBoard::findTaskById(size_t taskId)
{
	auto it = tasks.find(taskId);

	if (it != tasks.end())
	{
		return &(it->second);
	}

	return nullptr;
}

void TaskBoard::addTask(const Task& newTask)
{
	for (const auto& [id, task] : tasks)
	{
		if (task.getRequiredProduct() == newTask.getRequiredProduct() &&
			task.getRequiredQuantity() == newTask.getRequiredQuantity())
		{
			std::println("Such a task already exists!");
			return;
		}
	}

	tasks.insert({ newTask.getId(), newTask });
}
