#pragma once


#include "../flavor.hpp"


namespace Noodle {

class Chicken : Flavor {
public:
    Chicken(): Flavor("Chicken") {}

    int evaluate(Card*, int) const;
};
    
} // namespace Noodle