#pragma once


#include "../flavor.hpp"


namespace Noodle {

class Beaf : Flavor {
public:
    Beaf(): Flavor("Beaf") {}

    int evaluate(const Array<5>&) const;
};
    
} // namespace Noodle