#pragma once
#include <map>
#include <utility>
#include <print>
#include "PossibleProducts.h"

class Barn
{
private:
	std::map<PossibleProducts, unsigned> myProducts;

public:
	void addProduct(PossibleProducts product, unsigned quantity);
	void removeProduct(PossibleProducts product, unsigned quantity);
	bool isAvailable(PossibleProducts product, unsigned quantity);
	void printBarn() const;
};

