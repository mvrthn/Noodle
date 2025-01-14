#pragma once


#include "../ingredient.hpp"


namespace Noodle {
    
class Mushrooms : Ingredient {
public:
    Mushrooms(): Ingredient("Mushrooms") {}

    inline int id() const { return 2; }
    inline bool isVege() const { return true; }
    inline bool isProtein() const { return false; }
};

} // namespace Noodle