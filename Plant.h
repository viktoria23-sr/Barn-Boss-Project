#pragma once
#include <stdexcept>
#include "PossibleProducts.h"

struct Plant
{
	PossibleProducts type;
	unsigned currentCycle = 0;
	unsigned requiredCycle;

	Plant(PossibleProducts type_);

	void increaseCurrentCycle();
};

