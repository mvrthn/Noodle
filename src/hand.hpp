#pragma once 


#include "card.hpp"


constexpr int maxSize = 7;


namespace Noodle {

class Hand {
public:
    void add(Card*);
    Card* remove(int);
    bool isValid();

private:
    Card* cards[maxSize] = {nullptr};
    int size = 0;
};
    
} // namespace Noodle