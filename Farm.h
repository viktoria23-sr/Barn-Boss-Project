#pragma once
#include <vector>
#include <string>

class Farm
{
private:
	std::vector <std::string> plants;
	std::vector <std::string> animals;
	size_t croplandCapacity = 3;
	size_t farmlandCapacity = 3;

public:
	Farm() = default;
	Farm(std::vector<std::string>& plants_, std::vector<std::string>& animals_, size_t croplandCapacity_,
		size_t farmlandCapacity_) : plants(plants_), animals(animals_), croplandCapacity(croplandCapacity_),
		farmlandCapacity(farmlandCapacity_) { }

	void setCroplandCapacity(size_t cropsCapacity);
	size_t getCroplandCapacity() const;
	void setFarmlandCapacity(size_t animalsCapacity);
	size_t getFarmlandCapacity() const;
};

