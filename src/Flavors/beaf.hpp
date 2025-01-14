#pragma once


#include "../flavor.hpp"


namespace Noodle {

class Beaf : Flavor {
public:
    Beaf(): Flavor("Beaf") {}

    int evaluate(Card*, int) const;
};
    
} // namespace Noodle