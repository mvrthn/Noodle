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

bool Hand::isValid() {
    return cards.len() <= 5;
}

void Hand::update() {
    cards.update();
}
    
} // namespace Noodle
