#pragma once


#include "../flavor.hpp"


namespace Noodle {

class SoySouce : Flavor {
public:
    SoySouce(): Flavor("SoySouce") {}

    int evaluate(Card*, int) const;
};
    
} // namespace Noodle