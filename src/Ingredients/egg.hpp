#pragma once


#include "../ingredient.hpp"


namespace Noodle {
    
class Egg : Ingredient {
public:
    Egg(): Ingredient("Egg") {}

    inline int id() const { return 5; }
    inline bool isVege() const { return true; }
    inline bool isProtein() const { return false; }
};

} // namespace Noodle