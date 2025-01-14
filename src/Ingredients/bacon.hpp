#pragma once


#include "../ingredient.hpp"


namespace Noodle {
    
class Bacon : Ingredient {
public:
    Bacon(): Ingredient("Bacon") {}

    inline int id() { return 4; }
    inline bool isVege() { return false; }
    inline bool isProtein() { return true; }
};

} // namespace Noodle