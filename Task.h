#pragma once
#include <string>
#include "PossibleProducts.h"

class Task
{
protected:
	std::string id;
	PossibleProducts requiredProduct;
	unsigned long requiredQuantity;
	size_t rewardBalance;
	size_t rewardScore;
	bool isCompleted = false;

public:
	Task() = delete;
	Task(const std::string& id_, PossibleProducts requiredProduct_, unsigned long requiredQuantity_, size_t rewardBalance_,
		size_t rewardScore_) : id(id_), requiredProduct(requiredProduct_), requiredQuantity(requiredQuantity_),
		rewardBalance(rewardBalance_), rewardScore(rewardScore_) {}
};

