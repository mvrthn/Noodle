#include "deck.hpp"


constexpr int numOfCards = 66;

namespace Noodle {
    
Deck::Deck() {
    cards = (Card*) malloc(sizeof(Card) * numOfCards);
}

Deck::~Deck() {
    free(cards);
}

Card* Deck::drawCard() {
    return nullptr;
}

} // namespace Noodl 