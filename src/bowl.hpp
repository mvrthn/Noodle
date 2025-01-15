#pragma once 


#include "card.hpp"
#include "flavor.hpp"
#include "array.hpp"


namespace Noodle {

class Bowl {
public:
    bool add(Card*);
    Card* remove();
    int eat();
    bool pourOut();

private:
    Array<5> cards;
    Flavor* flavor = nullptr;
    bool isEaten = false;
};
    
} // namespace Noodle