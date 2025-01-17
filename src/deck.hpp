#pragma once 


#include "card.hpp"


constexpr int cardTypes = 11;
constexpr int numOfCards = 66;


namespace Noodle {

class Deck {
public:
    Deck();
    ~Deck();

    Card* drawCard();

private:
    Card* cards[numOfCards];
    Card* memSlot;
    int index = 0;

private:
    void shuffle();
};
    
} // namespace Noodle