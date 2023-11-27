#pragma once

class Card {
public:
    virtual bool isFlavor() = 0;
    virtual bool isIngredient() = 0;
    virtual const char* name() = 0;
};