#include "MarketItem.h"

unsigned MarketItem::getQuantity() const
{
	return quantity;
}

MarketItem::MarketItem(unsigned quantity_, unsigned price_) : quantity(quantity_), price(price_) { }

void MarketItem::setPrice(unsigned price_)
{
	price = price_;
}

unsigned MarketItem::getPrice() const
{
	return price;
}

void MarketItem::reduceQuantity(unsigned amount)
{
	if (amount > quantity)
	{
        throw std::invalid_argument("Error: Cannot reduce quantity below zero!");
    }
    
	quantity -= amount;
}

void MarketItem::increaseQuantity(unsigned amount)
{
	quantity += amount;
}
