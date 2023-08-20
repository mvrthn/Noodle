#ifndef NOODLE_MUSHROOMS_H
#define NOODLE_MUSHROOMS_H


#include "../Ingredient.hpp"

class Mushrooms : public Ingredient {
public:
    inline bool isVege() {return true;}
    inline bool isProtein() {return false;}
    inline int id() {return 2;}
	inline const char* name() {return "Mushrooms";}
};


#endif //NOODLE_MUSHROOMS_H