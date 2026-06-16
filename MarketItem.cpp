#include "MarketItem.h"

unsigned MarketItem::getQuantity() const
{
	return quantity;
}

void MarketItem::setPrice(double price_)
{
	if (price_ < 0)
	{
		throw std::invalid_argument("Price cannot be a negative number!");
	}

	price = price_;
}

double MarketItem::getPrice() const
{
	return price;
}

void MarketItem::reduceQuantity(unsigned amount)
{
	quantity -= amount;
}

void MarketItem::increaseQuantity(unsigned amount)
{
	quantity += amount;
}
