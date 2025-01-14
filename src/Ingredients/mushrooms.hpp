#pragma once


#include "../ingredient.hpp"


namespace Noodle {
    
class Mushrooms : Ingredient {
public:
    Mushrooms(): Ingredient("Mushrooms") {}

    inline int id() { return 2; }
    inline bool isVege() { return true; }
    inline bool isProtein() { return false; }
};

} // namespace Noodle