#include "bowl.hpp"


namespace Noodle {
    
bool Bowl::add(Card* card) {
    if(isEaten) {
        return false;
    }
    if(cards.len() >= 5) {
        return false;
    }
    if(card->isFlavor()) {
        if(flavor != nullptr) {
            return false;
        }
        flavor = (Flavor*) card;
    }
    cards.push(card);
    return true;
}

Card* Bowl::remove() {
    if(isEaten) {
        return nullptr;
    }
    if(cards.empty()) {
        return nullptr;
    }
    Card* card = cards.pop();
    if(card == flavor) {
        flavor = nullptr;
    }
    return card;
}

int Bowl::eat() {
    if(isEaten) {
        return -1;
    }
    if(cards.len() <= 2 || !flavor) {
        return -1;
    }
    isEaten = true;
    return flavor->evaluate(cards);
}

bool Bowl::pourOut() {
    if(isEaten) {
        return false;
    }
    cards.clear();
    flavor = nullptr;
    return true;
}

const Array<Bowl::Size>& Bowl::getData() const {
    return cards;
}

} // namespace Noodle