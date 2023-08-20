#ifndef NOODLE_TOFU_H
#define NOODLE_TOFU_H


#include "../Ingredient.hpp"

class Tofu : public Ingredient {
public:
    inline bool isVege() {return true;}
    inline bool isProtein() {return true;}
    inline int id() {return 3;}
	inline const char* name() {return "Tofu";}
};


#endif //NOODLE_TOFU_H