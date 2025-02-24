#pragma once


#include "../flavor.hpp"


namespace Noodle {

class SoySouce : Flavor {
public:
    SoySouce(): Flavor(19, "SoySouce") {}

    int evaluate(const Array<5>&) const;
};
    
} // namespace Noodle