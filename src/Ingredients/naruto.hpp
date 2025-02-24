#pragma once


#include "../ingredient.hpp"


namespace Noodle {
    
class Naruto : Ingredient {
public:
    Naruto(): Ingredient(5, "Naruto") {}

    inline bool isVege() const { return true; }
    inline bool isProtein() const { return false; }
};

} // namespace Noodle