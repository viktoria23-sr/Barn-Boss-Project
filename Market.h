#pragma once
#include <iostream>
#include "MarketItem.h"
#include <map>
#include "PossibleProducts.h"

class Market
{
private:
	std::map <PossibleProducts, MarketItem> marketCatalogue;

public:
	Market(const Market& other) = delete;
	Market& operator=(const Market& other) = delete;

	static Market& getInstance();

	void printCatalogue() const;
	MarketItem& getItem(PossibleProducts product);
	const MarketItem& getItem(PossibleProducts product) const;
};

