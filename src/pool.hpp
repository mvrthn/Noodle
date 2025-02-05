#pragma once 


#include "card.hpp"
#include "array.hpp"


namespace Noodle {

class Pool {
public:
    void add(Card*);
    Card* remove(int);
    void clear();

public:
    static constexpr int Size = 4;
    const Array<Size>& getData() const;

private:
    Array<Size> cards;
};
    
} // namespace Noodle