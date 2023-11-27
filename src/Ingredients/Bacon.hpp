#pragma once

#include "../Ingredient.hpp"

class Bacon : public Ingredient {
public:
    inline bool isVege() {return false;}
    inline bool isProtein() {return true;}
    inline int id() {return 4;}
	inline const char* name() {return "Bacon";}
};