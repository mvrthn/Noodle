#include <string.h>
#include <random>
#include <ctime>
#include "Deck.hpp"
#include "Ingredients/Bacon.hpp"
#include "Ingredients/Chives.hpp"
#include "Ingredients/Corn.hpp"
#include "Ingredients/Egg.hpp"
#include "Ingredients/Mushrooms.hpp"
#include "Ingredients/Naruto.hpp"
#include "Ingredients/Tofu.hpp"
#include "Flavors/Beaf.hpp"
#include "Flavors/Chicken.hpp"
#include "Flavors/Shrimp.hpp"
#include "Flavors/SoySouce.hpp"
#include "Flavors/Spicy.hpp"
#include "Specials/Nori.hpp"
#include "Specials/SpicyPepper.hpp"


Deck::Deck(bool advancedMode) {
    if(advancedMode) {
        stackSize = 89;
        poolOfCards = new int[14] {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 8, 12};    
    }
    else {
        stackSize = 66;
        poolOfCards = new int[11] {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6};
    }
    srand(time(NULL));
}

Card* Deck::getCardFromStack(char* errMsg) {
    if(!stackSize) {
        strcpy(errMsg, "No cards left on stack");
        return nullptr;
    }
    int r = rand() % stackSize;
    int i = -1;
    while(r >= 0) {
        i++;
        r -= *(poolOfCards + i);
    }
    poolOfCards[i]--;
    stackSize--;
    switch(i) {
    case 0:
        return new Bacon();
        break;
    case 1:
        return new Chives();
        break;
    case 2:
        return new Corn();
        break;
    case 3:
        return new Egg();
        break;
    case 4:
        return new Mushrooms();
        break;
    case 5:
        return new Naruto();
        break;
    case 6:
        return new Tofu();
        break;
    case 7:
        return new Beaf();
        break;
    case 8:
        return new Chicken();
        break;
    case 9:
        return new Schrimp();
        break;
    case 10:
        return new SoySouce();
        break;
    case 11:
        return new Spicy();
        break;
    case 12:
        return new Nori();
        break;
    case 13:
        return new SpicyPepper();
        break;
    }
    return nullptr;
}

Card* Deck::getCardFromPool(int index, char* errMsg) {
    Card* card = table[index];
    if(!card) {
        strcpy(errMsg, "No card at this position");
        return nullptr;
    }
    table[index] = getCardFromStack(errMsg);
    return card;
}

bool Deck::replaceTable(char* errMsg) {
    int n = 0;
    for(Card*& card : table) {
        if(card) delete card;
        card = getCardFromStack(errMsg);
        if(card) n++;
    }
    return n > 0;
}