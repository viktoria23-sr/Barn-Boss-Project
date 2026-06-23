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
	size_t currentTurn = 0;

	static constexpr int BUYABLE_PRODUCTS = 4;
	static constexpr int SELLABLE_PRODUCTS = 4;

public:
	Player(const std::string& id_, const std::string& username_, const std::string& password_,
	double balance, size_t score_);
	double checkBalance() const;
	size_t checkScore() const;
	void checkBarn() const;
	void checkFarm() const;
	size_t freeSlots(const std::vector<std::string>& v, size_t capacity);
	void expandCropland();
	void expandFarmland();
	void sowPlant(size_t seedId);
	void addAnimal(size_t animalId);
	void harvest();
	void openMarketCatalog();
	void buyItem(size_t productId, unsigned quantity);
	void sellItem(size_t productId, unsigned quantity);
	void showTaskBoard();
	void completeTask(size_t taskId);
	void completeTurn();

	void profileInfo() const override;
	void save(std::ostream& out) const override;
	void load(std::istream& in) override;
	std::string getRole() const override;

	std::partial_ordering operator <=> (const Player& other) const
	{
		if (auto cmp = other.score <=> score; cmp != 0)
		{
			return cmp;
		}

		if (auto cmp = other.balance <=> balance; cmp != 0)
		{
			return cmp;
		}

		int myId = std::stoi(id);
		int otherId = std::stoi(other.id);
		return myId <=> otherId;
	}

};

