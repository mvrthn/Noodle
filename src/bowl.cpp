#include "bowl.hpp"


namespace Noodle {
    
bool Bowl::add(Card* card) {
    if(size >= 5) {
        return false;
    }
    if(card->isFlavor()) {
        if(flavor != nullptr) {
            return false;
        }
        flavor = (Flavor*) card;
    }
    cards[size++] = card;
    return true;
}

Card* Bowl::remove() {
    if(size <= 0) {
        return nullptr;
    }
    Card* card = cards[--size];
    if(card == flavor) {
        flavor = nullptr;
    }
    cards[size] = nullptr;
    return card;
}

int Bowl::eat() {
    if(size <= 2) {
        return -1;
    }
    if(!flavor) {
        return -1;
    }
    return flavor->evaluate(cards, size);
}

void Bowl::pourOut() {
    for(int i = 0; i < size; i++) {
        cards[i] = nullptr;
    }
    flavor = nullptr;
    size = 0;
}

} // namespace Noodle