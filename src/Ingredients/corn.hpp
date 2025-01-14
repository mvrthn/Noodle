#pragma once


#include "../ingredient.hpp"


namespace Noodle {
    
class Corn : Ingredient {
public:
    Corn(): Ingredient("Corn") {}

    inline int id() { return 1; }
    inline bool isVege() { return true; }
    inline bool isProtein() { return false; }
};

} // namespace Noodle