#ifndef NOODLE_FLAVOR_H
#define NOODLE_FLAVOR_H


#include "Card.hpp"

class Flavor : public Card {
public:
    virtual int evaluate(Card*, int) = 0;
    virtual const char* name() = 0;
    inline bool isFlavor() {return true;}
    inline bool isIngredient() {return false;}
};


#endif //NOODLE_FLAVOR_H