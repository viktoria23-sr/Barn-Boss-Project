#include "Task.h"

Task::Task(size_t id_, PossibleProducts requiredProduct_, unsigned requiredQuantity_, size_t rewardBalance_, size_t rewardScore_) :
	id(id_), requiredProduct(requiredProduct_), requiredQuantity(requiredQuantity_),
	rewardBalance(rewardBalance_), rewardScore(rewardScore_) {}

PossibleProducts Task::getRequiredProduct() const
{
	return requiredProduct;
}

unsigned Task::getRequiredQuantity() const
{
	return requiredQuantity;
}

size_t Task::getRewardBalance() const
{
	return rewardBalance;
}

size_t Task::getRewardScore() const
{
	return rewardScore;
}

size_t Task::getId() const
{
	return id;
}

bool Task::getIsCompleted() const
{
	return isCompleted;
}

void Task::setCompleted()
{
	isCompleted = true;
}
