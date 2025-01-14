#pragma once 


#include "card.hpp"

namespace Noodle {

class Pool {
public:
    void add(Card*);
    Card* remove(int);

private:
    Card* cards[4];
};
    
} // namespace Noodle