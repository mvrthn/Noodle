#pragma once


#include "../ingredient.hpp"


namespace Noodle {
    
class Tofu : Ingredient {
public:
    Tofu(): Ingredient("Tofu") {}

    inline int id() { return 3; }
    inline bool isVege() { return true; }
    inline bool isProtein() { return false; }
};

} // namespace Noodle