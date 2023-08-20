#ifndef NOODLE_CHICKEN_H
#define NOODEL_CHICKEN_H

#include "../Flavor.hpp"

class Chicken : public Flavor {
public:
    int evaluate(Card*, int);
    inline const char* name() {return "Chicken";}
};


#endif //NOODLE_CHICKEN_H
