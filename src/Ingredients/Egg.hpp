#pragma once

#include "../Ingredient.hpp"

class Egg : public Ingredient {
public:
    inline bool isVege() {return false;}
    inline bool isProtein() {return true;}
    inline int id() {return 5;}
	inline const char* name() {return "Egg";}
};