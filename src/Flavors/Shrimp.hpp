#pragma once 

#include "../Flavor.hpp"

class Schrimp : public Flavor {
public:
    int evaluate(Card*, int);
    inline const char* name() {return "Schrimp";}
};