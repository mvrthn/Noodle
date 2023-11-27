#pragma once

#include "../Flavor.hpp"

class Spicy : public Flavor {
public:
    int evaluate(Card*, int);
    inline const char* name() {return "Spicy";}
};