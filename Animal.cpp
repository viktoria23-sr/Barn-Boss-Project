#include "Animal.h"

Animal::Animal(PossibleProducts type_) : type(type_)
{
	if (type != PossibleProducts::Cow && type != PossibleProducts::Chicken)
	{
		throw std::invalid_argument("An animal should be a chicken or a cow!");
	}

	if (type == PossibleProducts::Chicken)
	{
		requiredCycles = 3;
	}

	if (type == PossibleProducts::Cow)
	{
		requiredCycles = 5;
	}
}


void Animal::increaseCurrentCycle()
{
	currentCycle++;
}
