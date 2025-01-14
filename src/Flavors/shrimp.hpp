#pragma once


#include "../flavor.hpp"


namespace Noodle {

class Shrimp : Flavor {
public:
    Shrimp(): Flavor("Shrimp") {}

    int evaluate(Card*, int) const;
};
    
} // namespace Noodle