#pragma once 


#include "card.hpp"
#include "flavor.hpp"
#include "array.hpp"


namespace Noodle {

class Bowl {
public:
    bool add(Card*);
    Card* remove();
    int eat();
    bool pourOut();

public:
    static constexpr int Size = 5;
    const Array<Size>& getData() const;

private:
    Array<Size> cards;
    Flavor* flavor = nullptr;
    bool isEaten = false;
};
    
} // namespace Noodle