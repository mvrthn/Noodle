#include "pool.hpp"

#include <cassert>


namespace Noodle {

void Pool::add(Card* card) {
    cards.push(card);
}

Card* Pool::remove(int index) {
    return cards.remove(index);
}

void Pool::clear() {
    cards.clear();
}

const Array<Pool::Size>& Pool::getData() const {
    return cards;
}
    
} // namespace Noodle
