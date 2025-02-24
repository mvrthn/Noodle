#pragma once


#include "card.hpp"


namespace Noodle {

class Ingredient : public Card {
public:
    Ingredient(int id, std::string name): Card(id, name) {}

    inline bool isFlavor() const { return false; }
    inline bool isIngredient() const { return true; }
    
    virtual bool isVege() const = 0;
    virtual bool isProtein() const = 0;
};
    
} // namespace Noodle