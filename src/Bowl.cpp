#include <string.h>
#include "Bowl.hpp"

bool Bowl::addCard(Card* card, char* errMsg) {
    if(isEaten) {
        strcpy(errMsg, "Bowl is eaten");
        return false;
    }
    if(topIndex > 4) {
        strcpy(errMsg, "Bowl is full");
        return false;
    }
    if(card->isFlavor()) {
        if(flavor) {
            strcpy(errMsg, "Bowl already has flavor");
            return false;
        }
        flavor = (Flavor*) card;
    }
    cards[topIndex++] = card;
    return true;
}

Card* Bowl::removeCard(char* errMsg) {
    if(isEaten) {
        strcpy(errMsg, "Bowl is eaten");
        return nullptr;
    }
    if(topIndex == 0) {
        strcpy(errMsg, "Bowl is empty");
        return nullptr;
    }
    Card* card = cards[topIndex];
    cards[topIndex--] = nullptr;
    return card;
}

bool Bowl::eat(char* errMsg) {
    if(isEaten) {
        strcpy(errMsg, "Bowl is already eaten");
        return false;
    }
    if(!flavor) {
        strcpy(errMsg, "Bowl need to have flavor");
        return false;
    }
    for(int i = 0; i <= topIndex; i++) {
        if(cards[i]->isIngredient()) {
            isEaten = true;
            score = flavor->evaluate(*cards, topIndex);
            return true;
        }
    }
    strcpy(errMsg, "Bowl needs to have at least one ingredinet");
    return false;
}

bool Bowl::pourOut(char* errMsg) {
    if(isEaten) {
        strcpy(errMsg, "Bowl is eaten");
        return false;
    }
    if(topIndex == 0) {
        strcpy(errMsg, "Bowl is empty");
        return false;
    }
    for(int i = topIndex; i >= 0; i--) {
        delete cards[i];
        cards[i] = nullptr;
    }
    flavor = nullptr;
    topIndex = 0;
    return true;
}