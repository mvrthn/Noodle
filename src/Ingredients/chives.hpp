#pragma once


#include "../ingredient.hpp"


namespace Noodle {
    
class Chives : Ingredient {
public:
    Chives(): Ingredient(0, "Chives") {}

    inline bool isVege() const { return true; }
    inline bool isProtein() const { return false; }
};

} // namespace Noodle