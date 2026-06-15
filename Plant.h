#pragma once
#include <stdexcept>
#include "PossibleProducts.h"

struct Plant
{
	PossibleProducts type;
	unsigned currentCycle = 0;
	unsigned requiredCycle;

	Plant(PossibleProducts type_, unsigned requiredCycle_) : type(type_), requiredCycle(requiredCycle_)
	{
		if (type != PossibleProducts::WheatSeed && type != PossibleProducts::CornSeed)
		{
			throw std::invalid_argument("A plant in a farm must be a wheat seed or a corn seed!");
		}
	}

};

