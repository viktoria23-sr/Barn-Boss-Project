#pragma once
#include <stdexcept>

class MarketItem
{
private:
	unsigned quantity;
	unsigned price;

public:
	MarketItem(unsigned quantity_, unsigned price_);

	unsigned getQuantity() const;
	void increaseQuantity(unsigned amount);
	void reduceQuantity(unsigned amount);

	unsigned getPrice() const;
	void setPrice(double price_);
};

