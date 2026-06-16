#pragma once
#include "User.h"
#include "Farm.h"
#include "Barn.h"
#include "TaskBoard.h"
#include <vector>
#include <print>

class Player : public User
{
private:
	Barn barn;
	Farm farm;
	double balance = 100;
	size_t score = 0;

public:

	double checkBalance() const;
	size_t checkScore() const;
	void checkBarn() const;
	void checkFarm() const;
	size_t freeSlots(const std::vector<std::string>& v, size_t capacity);
	void expandCropland();
	void expandFarmland();
	void sowPlant(std::string seedId);
	void addAnimal(std::string animalId);
	void harvest();
	void openMarketCatalog();
	void buyItem(std::string productId, size_t quantity);
	void sellItem(std::string productId, std::string quantity);
	void showTaskBoard();
	void completeTask(const std::string& taskId);
	void completeTurn();

	void profileInfo() const override;
	void save(std::ostream& out) const override;
	void load(std::istream& in) override;
	std::string getRole() const override;

	std::partial_ordering operator <=> (const Player& other) const
	{
		if (auto cmp = score <=> other.checkScore(); cmp != 0)
		{
			return cmp;
		}

		if (auto cmp = balance <=> other.checkBalance(); cmp != 0)
		{
			return cmp;
		}

		return id <=> other.getId(); //ìîãà äà ãî íàïèøà ïðîñòî òàêà??
	}

};

