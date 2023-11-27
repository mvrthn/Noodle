#pragma once

#include "../Flavor.hpp"

class SoySouce : public Flavor {
public:
    int evaluate(Card*, int);
    inline const char* name() {return "SoySouce";}
};