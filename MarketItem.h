#pragma once
#include <stdexcept>

class MarketItem
{
private:
	unsigned quantity;
	double price;

public:
	MarketItem(unsigned quantity_, double price_) : quantity(quantity_), price(price_) 
	{	
		if (price < 0)
		{
			throw std::invalid_argument("Price cannot be a negative number!");
		}
	}

	unsigned getQuantity() const;
	double getPrice() const;
};

