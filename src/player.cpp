#include "player.hpp"

#include <cassert>


namespace Noodle {

void Player::addToHand(Card* card) {
    hand.add(card);
}

Card* Player::removeFromHand(int index) {
    return hand.remove(index);
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

bool Player::checkIfWon() {
    return eatenBowls >= 3;
}

void Player::checkIfInBounds(int i) {
    assert(i >= 0 && i < 3);
}

} // namespace Noodle