#pragma once


#include "../ingredient.hpp"


namespace Noodle {
    
class Bacon : Ingredient {
public:
    Bacon(): Ingredient("Bacon") {}

    inline int id() const { return 4; }
    inline bool isVege() const { return false; }
    inline bool isProtein() const { return true; }
};

} // namespace Noodle