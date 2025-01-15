#pragma once 


#include "card.hpp"
#include "array.hpp"


constexpr int maxSize = 7;


namespace Noodle {

class Hand {
public:
    void add(Card*);
    Card* remove(int);
    bool isValid();
    void update();

private:
    Array<maxSize> cards;
};
    
} // namespace Noodle