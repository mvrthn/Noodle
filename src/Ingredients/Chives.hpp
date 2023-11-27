#pragma once

#include "../Ingredient.hpp"

class Chives : public Ingredient {
public:
    inline bool isVege() {return true;}
    inline bool isProtein() {return false;}
    inline int id() {return 0;}
	inline const char* name() {return "Chives";}
};