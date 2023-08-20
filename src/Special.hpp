#ifndef NOODLE_SPECIAL_H
#define NOODLE_SPECIAL_H


#include "Card.hpp"

class Special : public Card {
public:
    inline bool isFlavor() {return false;}
    inline bool isIngredient() {return false;}
    virtual const char* name() = 0;
}; 


#endif //NOODLE_SPECIAL_H