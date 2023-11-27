#pragma once

#include "Card.hpp"

class Deck {
public:
    Deck(bool);
    inline ~Deck() {delete[] poolOfCards;}

    inline Card** getTable() {return table;}

    Card* getCardFromStack(char*);
    Card* getCardFromPool(int, char*);
    bool replaceTable(char*);
private:
    int stackSize;
    int* poolOfCards;
    Card* table[4];
};