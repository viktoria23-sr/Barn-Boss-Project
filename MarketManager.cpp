#include "MarketManager.h"

bool MarketManager::hasInstance = false;

MarketManager::MarketManager(const std::string& username_, const std::string& password_) :
    User("M_MANAGER", username_, password_)
{
    if (hasInstance)
    {
        throw std::runtime_error("Registration failed: A Market Manager already exists in the system!");
    }

    hasInstance = true;
}

MarketManager::~MarketManager()
{
    hasInstance = false;
}

void MarketManager::openMarketCatalog() const
{
    Market& market = Market::getInstance();
    market.printCatalogue();
}

void MarketManager::restock(size_t productId, unsigned quantity)
{
    if (productId < 1 || productId > 8) //магически числа???
    {
        throw std::invalid_argument("Error: Invalid product ID!");
        return;
    }

    Market& market = Market::getInstance();
    PossibleProducts product = getProductType(productId);

    market.getItem(product).increaseQuantity(quantity);
    std::println("Market restocked successfully! Added {} units of {}.", quantity, toString(product));
}

void MarketManager::changePrice(size_t productId, unsigned newPrice)
{
    if (productId < 1 || productId > 8) //магически числа???
    {
        throw std::invalid_argument("Error: Invalid product ID!");
        return;
    }

    Market& market = Market::getInstance();
    PossibleProducts product = getProductType(productId);
    MarketItem& item = market.getItem(product);
    item.setPrice(static_cast<double>(newPrice));

    std::println("Price of {} changed successfully to {} money.", toString(product), newPrice);
}

void MarketManager::profileInfo() const
{
    std::println("=== MARKET MANAGER PROFILE ===");
    std::println("ID: {}", id);
    std::println("Username: {}", username);
    std::println("Type: Market Manager");
}

std::string MarketManager::getRole() const
{
    return "MarketManager";
}
