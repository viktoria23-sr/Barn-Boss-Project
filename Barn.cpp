#include "Barn.h"

void Barn::addProduct(PossibleProducts product, unsigned quantity)
{
	myProducts[product] += quantity;

	if (myProducts.at(product) == quantity)
	{
		std::println("Product {} added successfully to the barn!", product);
		return;
	}

	std::println("The quantity of {} has been increased by {}.", product, quantity);
}

void Barn::removeProduct(PossibleProducts product, unsigned quantity)
{
	if (myProducts.at(product) < quantity)
	{
		std::println("The quantity of {} in the inventory is less!", product);
		return;
	}

	myProducts[product] -= quantity;
	std::println("The quantity of {} has been reduced by {}.", product, quantity);
}

bool Barn::isAvailable(PossibleProducts product, unsigned quantity)
{
	if (myProducts.at(product) < quantity)
	{
		return false;
	}

	return true;
}
