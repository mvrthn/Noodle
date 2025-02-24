#include "hand.hpp"


#include <cassert>


namespace Noodle {

void Hand::add(Card* card) {
    cards.push(card);
}

Card* Hand::remove(int index) {
    Card* card = cards.remove(index);
    return card;
}

bool Hand::isValid() const {
    return cards.len() <= LegalSize;
}

void Hand::update() {
    cards.update();
}

const Array<Hand::MaxSize>& Hand::getData() const {
    return cards;
}
    
} // namespace Noodle
