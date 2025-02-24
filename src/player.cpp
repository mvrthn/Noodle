#include "player.hpp"

#include <cassert>


namespace Noodle {

void Player::addToHand(Card* card) {
    hand.add(card);
}

Card* Player::removeFromHand(int index) {
    return hand.remove(index);
}

bool Player::handIsValid() const {
    return hand.isValid();
}

void Player::updateHand() {
    hand.update();
}

bool Player::addToBowl(int index, Card* card) {
    checkIfInBounds(index);
    return bowls[index].add(card);
}

Card* Player::removeFromBowl(int index) {
    checkIfInBounds(index);
    return bowls[index].remove();
}

int Player::eatBowl(int index) {
    checkIfInBounds(index);
    int points = bowls[index].eat();
    score += points;
    eatenBowls++;
    return points;
}

bool Player::pourOutBowl(int index) {
    checkIfInBounds(index);
    return bowls[index].pourOut();
}

bool Player::useSpoon() {
    if(spoons <= 0) {
        return false;
    }
    spoons--;
    return true;
}

bool Player::checkIfWon() const {
    return eatenBowls >= BowlNum;
}

const Array<Bowl::Size>& Player::getDataFromBowl(int index) const {
    checkIfInBounds(index);
    return bowls[index].getData();
}

const Array<Hand::MaxSize>& Player::getDataFromHand() const {
    return hand.getData();
}

void Player::checkIfInBounds(int i) {
    assert(i >= 0 && i < BowlNum);
}

} // namespace Noodle