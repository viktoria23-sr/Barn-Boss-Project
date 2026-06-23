#include "Market.h"

Market::Market()
{
	marketCatalogue.insert({ PossibleProducts::WheatSeed, MarketItem(20,10) });
	marketCatalogue.insert({ PossibleProducts::CornSeed, MarketItem(20,15) });
	marketCatalogue.insert({ PossibleProducts::Chicken, MarketItem(10,25) });
	marketCatalogue.insert({ PossibleProducts::Cow, MarketItem(5,50) });
	marketCatalogue.insert({ PossibleProducts::Wheat, MarketItem(20,15) });
	marketCatalogue.insert({ PossibleProducts::Corn, MarketItem(20,20) });
	marketCatalogue.insert({ PossibleProducts::Egg, MarketItem(15,30) });
	marketCatalogue.insert({ PossibleProducts::Milk, MarketItem(10,60) });
}

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
