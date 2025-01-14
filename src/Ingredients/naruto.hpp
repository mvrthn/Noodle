#pragma once


#include "../ingredient.hpp"


namespace Noodle {
    
class Naruto : Ingredient {
public:
    Naruto(): Ingredient("Naruto") {}

    inline int id() { return 5; }
    inline bool isVege() { return true; }
    inline bool isProtein() { return false; }
};

} // namespace Noodle