#include "Farm.h"

void Farm::incrementCroplandCapacity()
{
	croplandCapacity++;
}

size_t Farm::getCroplandCapacity() const
{
	return croplandCapacity;
}

void Farm::incrementFarmlandCapacity()
{
	farmlandCapacity++;
}

size_t Farm::getFarmlandCapacity() const
{
	return farmlandCapacity;
}

std::vector<Plant>& Farm::getPlants()
{
	return plants;
}

std::vector<Animal>& Farm::getAnimals()
{
	return animals;
}

void Farm::pushPlant(const Plant& plant)
{
	plants.push_back(plant);
}

void Farm::pushAnimal(const Animal& animal)
{
	animals.push_back(animal);
}

void Farm::removePlant(const Plant& plant)
{
	if (plants.empty())
	{
		std::println("There are no plants in the farm currently.");
		return;
	}

	for (auto it = plants.begin(); it != plants.end(); ++it)
	{
		if (it->type == plant.type && it->currentCycle >= it->requiredCycles)
		{
			plants.erase(it);
			return;
		}
	}
}

void Farm::removeAnimal(const Animal& animal)
{
	if (animals.empty())
	{
		std::println("There are no animals in the farm currently.");
		return;
	}

	for (auto it = animals.begin(); it != animals.end(); ++it)
	{
		if (it->type == animal.type && it->currentCycle >= it->requiredCycles)
		{
			animals.erase(it);
			return;
		}
	}
}

bool Farm::isSeedSowed(PossibleProducts seedType, Barn& playerBarn)
{
	if (seedType != PossibleProducts::WheatSeed && seedType != PossibleProducts::CornSeed)
	{
		std::println("The product is not a seed!");
		return false;
	}

	if (plants.size() >= croplandCapacity)
	{
		std::println("Seed cannot be planted: Cropland is full.");
		return false;
	}

	if (playerBarn.isAvailable(seedType, 1))
	{
		playerBarn.removeProduct(seedType, 1);
		plants.push_back(Plant(seedType));
		std::println("Plants planted successfully!");
		return true;
	}

	
		std::println("Not enough seeds in the barn.");
		return false;
}

bool Farm::isAnimalAdded(PossibleProducts animalType, Barn& playerBarn)
{
	if (animalType != PossibleProducts::Chicken && animalType != PossibleProducts::Cow)
	{
		std::println("The product is not an animal!");
		return false;
	}

	if (animals.size() >= farmlandCapacity)
	{
		std::println("Animal cannot be added: Farmland is full.");
		return false;
	}

	if (playerBarn.isAvailable(animalType, 1))
	{
		playerBarn.removeProduct(animalType, 1);
        animals.push_back(Animal(animalType));
        std::println("Animal added successfully!");
		return true;
	}

	std::println("Not enough animals in the barn.");
	return false;
}

void Farm::advanceCycle()
{
	for (auto& plant : plants)
	{
		plant.increaseCurrentCycle();
	}

	for (auto& animal : animals)
	{
		animal.increaseCurrentCycle();
	}
}

void Farm::printFarm() const
{
	std::println("Cropland capacity: {}", croplandCapacity);
	std::println("Current count of plants: {}", plants.size());
	std::println("FreeSlots in cropland: {}", croplandCapacity - plants.size());
	std::println("Farmland capacity: {}", farmlandCapacity);
	std::println("Current count of animals: {}", animals.size());
	std::println("FreeSlots in farmland: {}", farmlandCapacity - animals.size());
}
