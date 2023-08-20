#ifndef NOODLE_BEAF_H
#define NOODEL_BEAF_H

#include "../Flavor.hpp"

class Beaf : public Flavor {
public:
    int evaluate(Card*, int);
    inline const char* name() {return "Beaf";}
};


#endif //NOODLE_BEAF_H
