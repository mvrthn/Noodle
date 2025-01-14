#pragma once 


#include "card.hpp"
#include "array.hpp"


namespace Noodle {

class Pool {
public:
    void add(Card*);
    Card* remove(int);

private:
    Array<4> cards;
};
    
} // namespace Noodle