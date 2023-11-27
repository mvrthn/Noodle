#pragma once

#include "../Ingredient.hpp"

class Naruto : public Ingredient {
public:
    inline bool isVege() {return false;}
    inline bool isProtein() {return true;}
    inline int id() {return 5;}
	inline const char* name() {return "Naruto";}
};