#ifndef NOODLE_SCHRIM_H
#define NOODEL_SCHRIM_H

#include "../Flavor.hpp"

class Schrimp : public Flavor {
public:
    int evaluate(Card*, int);
    inline const char* name() {return "Schrim";}
};


#endif //NOODLE_SCHRIM_H
