#pragma once


#include "../ingredient.hpp"


namespace Noodle {
    
class Egg : Ingredient {
public:
    Egg(): Ingredient("Egg") {}

    inline int id() { return 5; }
    inline bool isVege() { return true; }
    inline bool isProtein() { return false; }
};

} // namespace Noodle