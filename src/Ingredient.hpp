#pragma once

#include "Card.hpp"

class Ingredient : public Card {
public:
    inline bool isFlavor() {return false;}
    inline bool isIngredient() {return true;}
    virtual bool isVege() = 0;
    virtual bool isProtein() = 0;
    virtual int id() = 0;
    virtual const char* name() = 0;
};