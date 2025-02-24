#pragma once 


#include "card.hpp"
#include "array.hpp"


namespace Noodle {

class Hand {
public:
    void add(Card*);
    Card* remove(int);
    bool isValid() const;
    void update();

public:
    static constexpr int MaxSize = 7;
    static constexpr int StartSize = 3;
    static constexpr int LegalSize = 5;
    const Array<MaxSize>& getData() const;

private:
    Array<MaxSize> cards;
};
    
} // namespace Noodle