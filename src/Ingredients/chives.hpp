#pragma once


#include "../ingredient.hpp"


namespace Noodle {
    
class Chives : Ingredient {
public:
    Chives(): Ingredient("Chives") {}

    inline int id() { return 0; }
    inline bool isVege() { return true; }
    inline bool isProtein() { return false; }
};

} // namespace Noodle