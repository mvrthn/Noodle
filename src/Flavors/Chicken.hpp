#pragma once

#include "../Flavor.hpp"

class Chicken : public Flavor {
public:
    int evaluate(Card*, int);
    inline const char* name() {return "Chicken";}
};