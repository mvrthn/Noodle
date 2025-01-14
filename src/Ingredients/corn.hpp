#pragma once


#include "../ingredient.hpp"


namespace Noodle {
    
class Corn : Ingredient {
public:
    Corn(): Ingredient("Corn") {}

    inline int id() const { return 1; }
    inline bool isVege() const { return true; }
    inline bool isProtein() const { return false; }
};

} // namespace Noodle