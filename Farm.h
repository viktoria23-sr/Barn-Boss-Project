#pragma once
#include <vector>
#include <variant>
#include "Plant.h"
#include "Animal.h"
#include "PossibleProducts.h"
#include "Barn.h"

class Farm
{
private:
	std::vector <Plant> plants;
	std::vector <Animal> animals;
	size_t croplandCapacity = 3;
	size_t farmlandCapacity = 3;

public:
	Farm() = default;

	void incrementCroplandCapacity();
	size_t getCroplandCapacity() const;
	void incrementFarmlandCapacity();
	size_t getFarmlandCapacity() const;

	std::vector<Plant>& getPlants();
	std::vector<Animal>& getAnimals(); //сега вече не знам дали са ми нужни тези гетъри
	
	void pushPlant(const Plant& plant);
	void pushAnimal(const Animal& animal);
	void removePlant(const Plant& plant);
	void removeAnimal(const Animal& animal);
	
	bool isSeedSowed(PossibleProducts seedType, Barn& playerBarn);
	bool isAnimalAdded(PossibleProducts animalType, Barn& playerBarn);
	void advanceCycle();
	void printFarm() const;
};

