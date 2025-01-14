#pragma once 


#include "card.hpp"
#include "Flavor.hpp"


namespace Noodle {

class Bowl {
public:
    bool add(Card*);
    Card* remove();
    int eat();
    void pourOut();

private:
    Card* cards[5] = {nullptr};
    Flavor* flavor = nullptr;
    int size = 0;
};
    
} // namespace Noodle