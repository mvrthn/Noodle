#ifndef NOODLE_CORN_H
#define NOODLE_CORN_H


#include "../Ingredient.hpp"

class Corn : public Ingredient {
public:
    inline bool isVege() {return true;}
    inline bool isProtein() {return false;}
    inline int id() {return 1;}
	inline const char* name() {return "Corn";}
};


#endif //NOODLE_CORN_H