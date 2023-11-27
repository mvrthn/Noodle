#pragma once

#include "../Flavor.hpp"

class Beaf : public Flavor {
public:
    int evaluate(Card*, int);
    inline const char* name() {return "Beaf";}
};