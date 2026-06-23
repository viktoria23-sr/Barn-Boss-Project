#pragma once

#include <string>
#include <stdexcept>

enum class PossibleProducts
{
	Wheat,
	Corn,
	Egg,
	Milk,
	WheatSeed,
	CornSeed,
	Chicken,
	Cow
};

PossibleProducts getProductType(size_t productId);
size_t getProductId(PossibleProducts product);
std::string toString(PossibleProducts product);

PossibleProducts getProductFromSeed(PossibleProducts seed);
PossibleProducts getProductFromAnimal(PossibleProducts animal);


