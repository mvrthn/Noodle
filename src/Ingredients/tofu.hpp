#pragma once


#include "../ingredient.hpp"


namespace Noodle {
    
class Tofu : Ingredient {
public:
    Tofu(): Ingredient("Tofu") {}

    inline int id() const { return 3; }
    inline bool isVege() const { return true; }
    inline bool isProtein() const { return false; }
};

} // namespace Noodle