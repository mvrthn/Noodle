#include "pool.hpp"

#include <cassert>


namespace Noodle {

void Pool::add(Card* card) {
    cards.push(card);
}

Card* Pool::remove(int index) {
    return cards.remove(index);
}
    
} // namespace Noodle
