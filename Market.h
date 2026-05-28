#pragma once
#include <tuple>
#include <vector>
#include "PossibleProducts.h"

class Market
{
private:
	std::vector < std::tuple < PossibleProducts, unsigned long, size_t, bool >> marketCatalogue;

	/*unsigned long quantity;
	size_t price;
	bool isAvailable = true;*/

public:
	//Как да го създам началното състояние на Market, с обекти ли???
};

