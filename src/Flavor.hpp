#pragma once

#include "Card.hpp"

class Flavor : public Card {
public:
    virtual int evaluate(Card*, int) = 0;
    virtual const char* name() = 0;
    inline bool isFlavor() {return true;}
    inline bool isIngredient() {return false;}
};