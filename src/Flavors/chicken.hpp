#pragma once


#include "../flavor.hpp"


namespace Noodle {

class Chicken : Flavor {
public:
    Chicken(): Flavor("Chicken") {}

    int evaluate(const Array<5>&) const;
};
    
} // namespace Noodle