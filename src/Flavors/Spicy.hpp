#ifndef NOODLE_SPICY_H
#define NOODEL_SPICY_H

#include "../Flavor.hpp"

class Spicy : public Flavor {
public:
    int evaluate(Card*, int);
    inline const char* name() {return "Spicy";}
};


#endif //NOODLE_SPICY_H
