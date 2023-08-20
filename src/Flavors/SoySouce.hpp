#ifndef NOODLE_SOYSOUCE_H
#define NOODEL_SOYSOUCE_H

#include "../Flavor.hpp"

class SoySouce : public Flavor {
public:
    int evaluate(Card*, int);
    inline const char* name() {return "SoySouce";}
};


#endif //NOODLE_SOYSOUCE_H
