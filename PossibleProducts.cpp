#include "PossibleProducts.h"

PossibleProducts getProductType(size_t productId)
{
    switch (productId)
    {
         case 1: return PossibleProducts::WheatSeed;
         case 2: return PossibleProducts::CornSeed;
         case 3: return PossibleProducts::Chicken;
         case 4: return PossibleProducts::Cow;
         case 5: return PossibleProducts::Wheat;
         case 6: return PossibleProducts::Corn;
         case 7: return PossibleProducts::Egg;
         case 8: return PossibleProducts::Milk;
         default : throw std::invalid_argument("Invalid product type!");
    }
}

size_t getProductId(PossibleProducts product)
{
    switch(product)
    {
        case PossibleProducts::WheatSeed : return 1;
        case PossibleProducts::CornSeed : return 2;
        case PossibleProducts::Chicken : return 3;
        case PossibleProducts::Cow : return 4;
        case PossibleProducts::Wheat : return 5;
        case PossibleProducts::Corn : return 6;
        case PossibleProducts::Egg : return 7;
        case PossibleProducts::Milk : return 8;
        default: return 0;
    }
}

const std::string& toString(PossibleProducts product)
{
    switch (product)
    {
        case PossibleProducts::Wheat : return "Wheat";
        case PossibleProducts::Corn: return "Corn";
        case PossibleProducts::Egg: return "Egg";
        case PossibleProducts::Milk: return "Milk";
        case PossibleProducts::WheatSeed: return "Wheat seed";
        case PossibleProducts::CornSeed: return "Corn seed";
        case PossibleProducts::Chicken: return "Chicken";
        case PossibleProducts::Cow: return "Cow";
        default: return "Unknown";
    }
}

PossibleProducts getProductFromSeed(PossibleProducts seed)
{
    switch (seed)
    {
    case PossibleProducts::WheatSeed:
        return PossibleProducts::Wheat;
    case PossibleProducts::CornSeed:
        return PossibleProducts::Corn;
    default:
        throw std::invalid_argument("Invalid product type!");
    }
}

PossibleProducts getProductFromAnimal(PossibleProducts animal)
{
    switch (animal)
    {
    case PossibleProducts::Chicken:
        return PossibleProducts::Egg;
    case PossibleProducts::Cow:
        return PossibleProducts::Milk; 
    default:
        throw std::invalid_argument("Invalid product type!");
    }
}


