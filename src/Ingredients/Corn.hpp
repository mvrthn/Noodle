#pragma once

#include "../Ingredient.hpp"

class Corn : public Ingredient {
public:
    inline bool isVege() {return true;}
    inline bool isProtein() {return false;}
    inline int id() {return 1;}
	inline const char* name() {return "Corn";}
};