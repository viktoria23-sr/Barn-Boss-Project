#include "Player.h"

Player::Player(const std::string& id_, const std::string& username_, const std::string& password_,
	double balance_, size_t score_) : User(id_, username_, password_), balance(balance_), 
	score(score_)
{
	if (balance < 0)
	{
		throw std::invalid_argument("Balance cannot be a negative number!");
	}
}

double Player::checkBalance() const
{
	return balance;
}

size_t Player::checkScore() const
{
	return score;
}

void Player::checkBarn() const
{
	barn.printBarn();
}

void Player::checkFarm() const
{
	farm.printFarm();
}

void Player::expandCropland()
{
	size_t currentCapacity = farm.getCroplandCapacity();

	size_t neededPrice = 50 * currentCapacity;
	size_t minRequiredScore = currentCapacity * 10;

	if (score < minRequiredScore)
	{
		std::println("Cannot expand cropland: Minimum Score of {} required. Your Score: {}.", minRequiredScore, score);
		return;
	}

	if (balance < neededPrice)
	{
		std::println("Cannot expand cropland: Needed Price : {}. Your Current Balance: {}.", neededPrice, balance);
		return;
	}

	balance -= neededPrice;
	farm.incrementCroplandCapacity();
	this->completeTurn();
}

void Player::expandFarmland()
{
	size_t currentCapacity = farm.getFarmlandCapacity();

	size_t neededPrice = 50 * currentCapacity;
	size_t minRequiredScore = currentCapacity * 10;

	if (score < minRequiredScore)
	{
		std::println("Cannot expand cropland: Minimum Score of {} required. Your Score: {}.", minRequiredScore, score);
		return;
	}

	if (balance < neededPrice)
	{
		std::println("Cannot expand cropland: Needed Price : {}. Your Current Balance: {}.", neededPrice, balance);
		return;
	}

	balance -= neededPrice;
	farm.incrementFarmlandCapacity();
	this->completeTurn();
}

void Player::sowPlant(size_t seedId)
{
	PossibleProducts seedType = getProductType(seedId);

	if (farm.isSeedSowed(seedType, barn))
	{
		barn.removeProduct(seedType, 1);
		farm.pushPlant(Plant(seedType));
		std::println("Seed planted successfully!");
		farm.advanceCycle();
	}

	this->completeTurn();
}

void Player::addAnimal(size_t animalId)
{
	PossibleProducts animalType = getProductType(animalId);

	if (farm.isAnimalAdded(animalType, barn))
	{
		barn.removeProduct(animalType, 1);
		farm.pushAnimal(Animal(animalType));
		std::println("Animal added successfully!");
		farm.advanceCycle();
	}

	this->completeTurn();
}

void Player::harvest()
{
	bool hasHarvestedAnything = false;
	
	auto& plants = farm.getPlants();

	for (int i = (int)plants.size() - 1; i >= 0; i--)
	{
		if (plants[i].currentCycle >= plants[i].requiredCycles)
		{
			PossibleProducts finalProduct = getProductFromSeed(plants[i].type);

			barn.addProduct(finalProduct, 1);
			plants.erase(plants.begin() + i);
			hasHarvestedAnything = true;
		}
	}

	auto& animals = farm.getAnimals();
	for (int i = (int)animals.size() - 1; i >= 0; i--)
	{
		if (animals[i].currentCycle >= animals[i].requiredCycles)
		{
			PossibleProducts finalProduct = getProductFromAnimal(animals[i].type);

			barn.addProduct(finalProduct, 1);
			animals.erase(animals.begin() + i);
			hasHarvestedAnything = true;
		}
	}

	if (hasHarvestedAnything)
	{
		std::println("Harvest completed!");
		this->completeTurn();
	}
	else
	{
		std::println("Nothing is ready to be harvested right now.");
	}
}

void Player::openMarketCatalog()
{
	Market& market = Market::getInstance();
	market.printCatalogue();
}

void Player::buyItem(size_t productId, unsigned quantity)
{
	if (productId > BUYABLE_PRODUCTS)
	{
		std::println("You cannot buy products that are not of type WheatSeed/CornSeed/Chicken/Cow.");
		return;
	}

	PossibleProducts product = getProductType(productId);
	Market& market = Market::getInstance();
	MarketItem& marketItem = market.getItem(product);

	if (marketItem.getQuantity() < quantity)
	{
		std::println("The market does not have enough stock! Available quantity: {}.", marketItem.getQuantity());
		return;
	}

	double totalPrice = marketItem.getPrice() * quantity; 

	if (balance < totalPrice)
	{
		std::println("You don't have enough money! Needed: {} gold. Your Balance: {}.", totalPrice, balance);
		return;
	}

	balance -= totalPrice;
	barn.addProduct(product, quantity);

	marketItem.reduceQuantity(quantity);

	std::println("The purchase was successful! Bought {}x {} for {} money.", quantity, toString(product), totalPrice);

	this->completeTurn();
}

void Player::sellItem(size_t productId, unsigned quantity)
{
	if (productId <= BUYABLE_PRODUCTS || productId > (BUYABLE_PRODUCTS + SELLABLE_PRODUCTS))
	{
		std::println("You can only sell final products (Wheat/Corn/Egg/Milk).");
		return;
	}

	PossibleProducts product = getProductType(productId);

	if (!barn.isAvailable(product, quantity))
	{
		std::println("You don't have enough {} in your barn to sell!", toString(product));
		return;
	}

	Market& market = Market::getInstance();
	MarketItem& marketItem = market.getItem(product);

	double totalEarnings = marketItem.getPrice() * quantity;

	barn.removeProduct(product, quantity);

	balance += totalEarnings;

	marketItem.increaseQuantity(quantity);

	std::println("The sale was successful! Sold {}x {} for {} money.", quantity, toString(product), totalEarnings);

	this->completeTurn();
}

void Player::showTaskBoard() const
{
	TaskBoard& taskBoard = TaskBoard::getInstance();

	if (taskBoard.getTasks().empty())
	{
		std::println("There are no unfinished tasks.");
		return;
	}

	for (const auto& [id, task] : taskBoard.getTasks())
	{
		std::println("TaskId: {}, RequiredProductType: {}, RequiredQuantity: {}, RewardBalance: {}, RewardScore: {}",
			task.getId(), toString(task.getRequiredProduct()), task.getRequiredQuantity(), task.getRewardBalance(), task.getRewardScore());
	}
}

void Player::completeTask(size_t taskId)
{
	TaskBoard& taskBoard = TaskBoard::getInstance();
	Task* targetTask = taskBoard.findTaskById(taskId);

	if (targetTask == nullptr)
	{
		std::println("Error: Task with ID {} does not exist!", taskId);
		return;
	}

	PossibleProducts requiredProduct = targetTask->getRequiredProduct();
	size_t requiredQuantity = targetTask->getRequiredQuantity();

	if (!barn.isAvailable(requiredProduct, requiredQuantity))
	{
		std::println("Error: You don't have enough {} in your barn!", toString(requiredProduct));
		return;
	}

	barn.removeProduct(requiredProduct, requiredQuantity);
	
	balance += targetTask->getRewardBalance();
	score += targetTask->getRewardScore();

	std::println("Task {} completed successfully! Received {} money and {} score.",
		taskId, targetTask->getRewardBalance(), targetTask->getRewardScore());
	
	taskBoard.removeTaskById(taskId);
	this->completeTurn();
}

void Player::profileInfo() const
{
	std::println("=== PLAYER PROFILE ===");
	std::println("ID: {}", id);
	std::println("Username: {}", username);
	std::println("Type: Player");
	std::println("Score: ", score);
	std::println("Balance: {}", balance);
}

void Player::completeTurn()
{
	currentTurn++;
	farm.advanceCycle();
}

void Player::save(std::ostream& out) const
{
	User::save(out);
	out << " " << this->balance << " " << this->score;
}

void Player::load(std::istream& in)
{
	double loadedBalance = 0.0;
	size_t loadedScore = 0;

	in >> loadedBalance >> loadedScore;

	balance = loadedBalance;
	score = loadedScore;
}

std::string Player::getRole() const
{
	return "Player";
}

