#include "deck.hpp"

#include <algorithm>

#include "Ingredients/bacon.hpp"
#include "Ingredients/chives.hpp"
#include "Ingredients/corn.hpp"
#include "Ingredients/egg.hpp"
#include "Ingredients/mushrooms.hpp"
#include "Ingredients/naruto.hpp"
#include "Ingredients/tofu.hpp"

#include "Flavors/beaf.hpp"
#include "Flavors/chicken.hpp"
#include "Flavors/shrimp.hpp"
#include "Flavors/soysouce.hpp"


constexpr int cardTypes = 11;
constexpr int numOfCards = 66;

namespace Noodle {
    
Deck::Deck() {
    cards = (Card*) malloc(sizeof(Card) * numOfCards);
    for(int i = 0; i < numOfCards; i++) {
        switch(i / cardTypes) {
            case 0:
                new(cards + i) Bacon();
                break;
            case 1:
                new(cards + i) Chives();
                break;
            case 2:
                new(cards + i) Corn();
                break;
            case 3:
                new(cards + i) Egg();
                break;
            case 4:
                new(cards + i) Mushrooms();
                break;
            case 5:
                new(cards + i) Naruto();
                break;
            case 6:
                new(cards + i) Tofu();
                break;
            case 7:
                new(cards + i) Beaf();
                break;
            case 8:
                new(cards + i) Chicken();
                break;
            case 9:
                new(cards + i) Shrimp();
                break;
            case 10:
                new(cards + i) SoySouce();
                break;
        }
    }
    std::random_shuffle(cards, cards + numOfCards);
}

Deck::~Deck() {
    free(cards);
}

Card* Deck::drawCard() {
    return nullptr;
}

} // namespace Noodl 