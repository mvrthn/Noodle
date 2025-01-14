#include "hand.hpp"


#include <cassert>


namespace Noodle {

void Hand::add(Card* card) {
    assert(size < maxSize);
    cards[size++] = card;
}

Card* Hand::remove(int index) {
    assert(index >= 0 && index < size);
    assert(size > 0);
    Card* card = cards[index];
    for(int i = index; i < size - 1; i++) {
        cards[i] = cards[i + 1];
    }
    cards[--size] = nullptr;
    return card;
}

bool Hand::isValid() {
    return size <= 5;
}
    
} // namespace Noodle
