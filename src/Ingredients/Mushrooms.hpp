#pragma once

#include "../Ingredient.hpp"

class Mushrooms : public Ingredient {
public:
    inline bool isVege() {return true;}
    inline bool isProtein() {return false;}
    inline int id() {return 2;}
	inline const char* name() {return "Mushrooms";}
};