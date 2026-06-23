#pragma once
#include <string>
#include "PossibleProducts.h"

class Task
{
protected:
	size_t id;
	PossibleProducts requiredProduct;
	unsigned requiredQuantity;
	size_t rewardBalance;
	size_t rewardScore;
	bool isCompleted = false;

public:
	Task() = delete;
	Task(size_t id_, PossibleProducts requiredProduct_, unsigned requiredQuantity_, size_t rewardBalance_,
		size_t rewardScore_);
	PossibleProducts getRequiredProduct() const;
	unsigned getRequiredQuantity() const;
	size_t getRewardBalance() const;
	size_t getRewardScore() const;
	size_t getId() const;
	bool getIsCompleted() const;
	void setCompleted();
};

