#pragma once


#include "../ingredient.hpp"


namespace Noodle {
    
class Mushrooms : Ingredient {
public:
    Mushrooms(): Ingredient(2, "Mushrooms") {}

    inline bool isVege() const { return true; }
    inline bool isProtein() const { return false; }
};

} // namespace Noodle