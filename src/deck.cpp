#include "deck.hpp"

#include <algorithm>
#include <random>
#include <iterator>

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


namespace Noodle {
    
Deck::Deck() {
    memSlot = (Card*) malloc(sizeof(Card) * numOfCards);
    for(int i = 0; i < numOfCards; i++) {
        switch(i / cardTypes) {
            case 0:
                cards[i] = (Card*) new(memSlot + i) Bacon();
                break;
            case 1:
                cards[i] = (Card*) new(memSlot + i) Chives();
                break;
            case 2:
                cards[i] = (Card*) new(memSlot + i) Corn();
                break;
            case 3:
                cards[i] = (Card*) new(memSlot + i) Egg();
                break;
            case 4:
                cards[i] = (Card*) new(memSlot + i) Mushrooms();
                break;
            case 5:
                cards[i] = (Card*) new(memSlot + i) Naruto();
                break;
            case 6:
                cards[i] = (Card*) new(memSlot + i) Tofu();
                break;
            case 7:
                cards[i] = (Card*) new(memSlot + i) Beaf();
                break;
            case 8:
                cards[i] = (Card*) new(memSlot + i) Chicken();
                break;
            case 9:
                cards[i] = (Card*) new(memSlot + i) Shrimp();
                break;
            case 10:
                cards[i] = (Card*) new(memSlot + i) SoySouce();
                break;
        }
    }
    shuffle();
}

Deck::~Deck() {
    free(memSlot);
}

Card* Deck::drawCard() {
    if(index >= numOfCards) {
        return nullptr;
    }
    return cards[index++];
}

void swap(Card** a, Card** b) {
    int size = sizeof(Card);
    Card* temp = *a;
    *a = *b;
    *b = temp;   
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards, cards  + numOfCards - 1, g);
}

} // namespace Noodl 