#pragma once 


#include "card.hpp"


namespace Noodle {

class Deck {
public:
    Deck();
    ~Deck();

    Card* drawCard();

private:
    Card* cards;
    int index = 0;
};
    
} // namespace Noodle