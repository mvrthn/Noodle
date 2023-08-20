#include <string.h>
#include "Player.hpp"

Bowl& Player::getBowl(int index) {
    return bowls[index];
}

Bowl* Player::getBowls() {
    return bowls;
}

int Player::getHandSize() {
    return hand.size();
}

Card* Player::getHand() {
    return *hand.data();
}

void Player::addToHand(Card* card) {
    hand.push_back(card);
}

void Player::removeFromHand(int index){
    delete hand[index];
    hand.erase(hand.begin() + index);
}

bool Player::addCardToBowl(int cardIndex, int bowlIndex, char* errMsg) {
    bool result = bowls[bowlIndex].addCard(hand[cardIndex], errMsg); 
    if(!result) {
        return false;
    }
    hand.erase(hand.begin() + cardIndex);
    return true;
}

bool Player::drawCard(Deck* deck, bool fromStack, int index, char* errMsg) {
    Card* card = nullptr;
    if(fromStack) {
        card = deck->getCardFromStack(errMsg);
    }
    else 
    {
        card = deck->getCardFromPool(index, errMsg);
    }
    if(card) {
        hand.push_back(card);
        return true;
    }
    return false;
}

bool Player::replaceTable(Deck* deck, char* errMsg) {
    return deck->replaceTable(errMsg);
}

bool Player::eatBowl(int index, char* errMsg) {
    return bowls[index].eat(errMsg);
}

bool Player::pourOutBowl(int index, char* errMsg) {
    return bowls[index].pourOut(errMsg);
}

bool Player::useSpoon(Player* player, int index, char* errMsg) {
    if(spoons == 0) {
        strcpy(errMsg, "You have no spoon left");
        return false;
    }
    Card* card = player->getBowl(index).removeCard(errMsg);
    if(!card) {
        return false;
    }
    hand.push_back(card);
    spoons--;
    return true;
}

bool Player::useTakenCard(Player* player, int index, char* errMsg) {
    Card* card = hand.back();
    bool b = player->getBowl(index).addCard(card, errMsg);
    if(!b) {
        return false;
    }
    hand.pop_back();
    return true;
}