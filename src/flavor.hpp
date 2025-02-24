#pragma once


#include "card.hpp"
#include "array.hpp"


namespace Noodle {

class Flavor : public Card {
public:
    Flavor(int id, std::string name): Card(id, name) {}

    inline bool isFlavor() const { return true; }
    inline bool isIngredient() const { return false; }

    virtual int evaluate(const Array<5>&) const = 0;
};
    
} // namespace Noodle