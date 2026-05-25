#pragma once
#include <vector>
#include <utility>
#include "PossibleProducts.h"

class Barn
{
private:
	std::vector <std::pair<PossibleProducts, unsigned long>> myProducts;

public:
	void addProduct(PossibleProducts product, unsigned long quantity);
};

