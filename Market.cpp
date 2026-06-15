#include "Market.h"

Market& Market::getInstance()
{
	static Market instance;
	return instance;
}

void Market::printCatalogue() const
{
	std::cout << "--------     MARKET CATALOGUE     --------" << std::endl;

	for (const auto& [product, item] : marketCatalogue)
	{
		std::cout << toString(product) <<  "   Quantity: " << item.getQuantity() <<  
			"   Price: " << item.getPrice() << std::endl;
	}
}

MarketItem& Market::getItem(PossibleProducts product)
{
	return marketCatalogue.at(product);
}

const MarketItem& Market::getItem(PossibleProducts product) const
{
	return marketCatalogue.at(product);
}
