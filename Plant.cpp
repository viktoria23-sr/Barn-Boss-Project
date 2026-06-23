#include "Plant.h"

Plant::Plant(PossibleProducts type_) : type(type_)
{
	if (type != PossibleProducts::WheatSeed && type != PossibleProducts::CornSeed)
	{
		throw std::invalid_argument("A plant in a farm must be a wheat seed or a corn seed!");
	}

	if (type == PossibleProducts::WheatSeed)
	{
		requiredCycles = 3;
	}

	if (type == PossibleProducts::CornSeed)
	{
		requiredCycles = 4;
	}
}

void Plant::increaseCurrentCycle()
{
	currentCycle++;
}
