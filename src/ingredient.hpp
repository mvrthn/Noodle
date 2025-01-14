#pragma once


#include "card.hpp"


namespace Noodle {

class Ingredient : public Card {
public:
    Ingredient(std::string name): Card(name) {}

    inline bool isFlavor() const { return false; }
    inline bool isIngredient() const { return true; }
    
    virtual int id() const = 0;
    virtual bool isVege() const = 0;
    virtual bool isProtein() const = 0;
};
    
} // namespace Noodle