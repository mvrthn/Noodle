#pragma omce


#include "card.hpp"


namespace Noodle {

class Flavor : public Card {
public:
    Flavor(std::string name): Card(name) {}

    inline bool isFlavor() const { return true; }
    inline bool isIngredient() const { return false; }

    virtual int evaluate(Card**, int) const = 0;
};
    
} // namespace Noodle