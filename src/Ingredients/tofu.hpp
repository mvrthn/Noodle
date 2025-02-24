#pragma once


#include "../ingredient.hpp"


namespace Noodle {
    
class Tofu : Ingredient {
public:
    Tofu(): Ingredient(3, "Tofu") {}

    inline bool isVege() const { return true; }
    inline bool isProtein() const { return false; }
};

} // namespace Noodle