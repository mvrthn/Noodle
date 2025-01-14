#pragma once


#include "../ingredient.hpp"


namespace Noodle {
    
class Naruto : Ingredient {
public:
    Naruto(): Ingredient("Naruto") {}

    inline int id() const { return 5; }
    inline bool isVege() const { return true; }
    inline bool isProtein() const { return false; }
};

} // namespace Noodle