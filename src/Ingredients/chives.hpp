#pragma once


#include "../ingredient.hpp"


namespace Noodle {
    
class Chives : Ingredient {
public:
    Chives(): Ingredient("Chives") {}

    inline int id() const { return 0; }
    inline bool isVege() const { return true; }
    inline bool isProtein() const { return false; }
};

} // namespace Noodle