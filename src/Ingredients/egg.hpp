#pragma once


#include "../ingredient.hpp"


namespace Noodle {
    
class Egg : Ingredient {
public:
    Egg(): Ingredient(5, "Egg") {}

    inline bool isVege() const { return true; }
    inline bool isProtein() const { return false; }
};

} // namespace Noodle