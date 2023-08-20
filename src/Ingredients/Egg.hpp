#ifndef NOODLE_EGG_H
#define NOODLE_EGG_H


#include "../Ingredient.hpp"

class Egg : public Ingredient {
public:
    inline bool isVege() {return false;}
    inline bool isProtein() {return true;}
    inline int id() {return 5;}
	inline const char* name() {return "Egg";}
};


#endif //NOODLE_EGG_H