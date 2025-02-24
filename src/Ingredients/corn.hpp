#pragma once


#include "../ingredient.hpp"


namespace Noodle {
    
class Corn : Ingredient {
public:
    Corn(): Ingredient(1, "Corn") {}

    inline bool isVege() const { return true; }
    inline bool isProtein() const { return false; }
};

} // namespace Noodle