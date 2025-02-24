#pragma once


#include "../flavor.hpp"


namespace Noodle {

class Shrimp : Flavor {
public:
    Shrimp(): Flavor(18, "Shrimp") {}

    int evaluate(const Array<5>&) const;
};
    
} // namespace Noodle