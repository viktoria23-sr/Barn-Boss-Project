#include "TaskBoard.h"

int TaskBoard::uncompletedTasks = 2;

TaskBoard::TaskBoard()
{
	tasks = { Task("1", PossibleProducts::Wheat, 5, 50, 10), Task("2", PossibleProducts::Milk, 3, 120, 20) };
}