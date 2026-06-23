#pragma once
#include "PossibleProducts.h"
#include <stdexcept>

struct Animal
{
	PossibleProducts type;
	unsigned currentCycle = 0;
	unsigned requiredCycle;

	Animal(PossibleProducts type_);

    void increaseCurrentCycle();
};

