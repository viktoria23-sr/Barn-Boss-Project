#include "Barn.h"

void Barn::addProduct(PossibleProducts product, unsigned quantity)
{
	if (quantity == 0)
	{
		std::println("There is no point in adding a product with 0 quantity.");
		return;
	}

	auto it = myProducts.find(product);

	if (it == myProducts.end())
	{
		myProducts[product] = quantity;
		std::println("Product {} added successfully to the barn!", toString(product));
		return;
	}

	it->second += quantity;
	std::println("The quantity of {} has been increased by {}.", toString(product), quantity);
}


void Barn::removeProduct(PossibleProducts product, unsigned quantity)
{
	if (quantity == 0)
	{
		std::println("There is no point in removing 0 from the quantity of a product!");
		return;
	}

	auto it = myProducts.find(product);

	if (it == myProducts.end() || it->second < quantity)
	{
		std::println("The quantity of {} in the inventory is less!", toString(product));
		return;
	}

	it->second -= quantity;
	std::println("The quantity of {} has been reduced by {}.", toString(product), quantity);

	if (it->second == 0)
	{
		myProducts.erase(it);
	}
}

bool Barn::isAvailable(PossibleProducts product, unsigned quantity)
{
	auto it = myProducts.find(product);

	if (it == myProducts.end())
	{
		return quantity == 0;
	}
	
	return it->second >= quantity;
}

void Barn::printBarn() const
{
	if (myProducts.empty())
	{
		std::println("The barn is currently empty.");
		return;
	}

	std::println("Barn products: ");

	for (const auto& [product, quantity]: myProducts)
	{
		std::println("ProductType: {}, Quantity: {}", toString(product), quantity);
	}
}

