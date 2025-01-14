#include "pool.hpp"

#include <cassert>


namespace Noodle {

void Pool::add(Card* card) {
    for(auto& c : cards) {
        if(c == nullptr) {
            c = card;
            return;
        }
    }
}

Card* Pool::remove(int index) {
    assert(index >= 0 && index < 4);

    Card* card = cards[index];
    cards[index] = nullptr;
    return card;
}
    
} // namespace Noodle
