#pragma once


#include "../ingredient.hpp"


namespace Noodle {
    
class Bacon : Ingredient {
public:
    Bacon(): Ingredient(4, "Bacon") {}

    inline bool isVege() const { return false; }
    inline bool isProtein() const { return true; }
};

} // namespace Noodle