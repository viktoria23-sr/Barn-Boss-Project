#pragma once
#include "User.h"
#include "Market.h"

class MarketManager : public User
{
private:
	static bool hasInstance;

	static constexpr size_t MIN_PRODUCT_ID = 1;
	static constexpr size_t MAX_PRODUCT_ID = 8;
public:
	MarketManager() = default;
	MarketManager(const std::string& username_, const std::string& password_);
	~MarketManager();

	void openMarketCatalog() const;
	void restock(size_t productId, unsigned quantity);
	void changePrice(size_t productId, unsigned newPrice);
	void profileInfo() const override;
	std::string getRole() const override;
};

