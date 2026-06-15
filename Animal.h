#pragma once
#include "PossibleProducts.h"
#include <stdexcept>

struct Animal
{
	PossibleProducts type;
	unsigned currentCycle = 0;
	unsigned requiredCycle;

	Animal(PossibleProducts type_, unsigned requiredCycle_) : type(type_), requiredCycle(requiredCycle_)
	{
		if (type != PossibleProducts::Cow && type != PossibleProducts::Chicken)
		{
			throw std::invalid_argument("An animal should be a chicken or a cow!");
		}
	}

    void increaseCurrentCycle();
};

