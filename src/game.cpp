#include "game.hpp"


namespace Noodle {

template<int N> 
bool Game<N>::drawCardFromDeck() {
    Card* card = deck.drawCard();
    if(!card) {
        return false;
    }
    playerOnMove.addToHand(card);
    return true;
}

template<int N> 
bool Game<N>::drawCardFromPool(int index) {
    Card* card = pool.remove(index);
    if(!card) {
        return false;
    }
    playerOnMove.addToHand(card);
    Card* newCard = deck.drawCard();
    if(newCard) {
        pool.add(newCard);
    }
    return true;
}

template<int N> 
bool Game<N>::redrawPool() {
    pool.clear();
    for(int i = 0; i < 4; i++) {
        Card* card = deck.drawCard();
        if(!card) {
            return false;
        }
        pool.add(card);
    }
    return true;
}

template<int N> 
bool Game<N>::addCardToBowl(int cardIndex, int bowlIndex) {
    Card* card = playerOnMove.removeFromHand(cardIndex);
    if(!card) {
        return false;
    }
    if(playerOnMove.addToBowl(bowlIndex, card)) {
        playerOnMove.updateHand();
        return true;
    }
    playerOnMove.addToHand(card);
    return false;
}

template<int N> 
bool Game<N>::pourOutBowl(int index) {
    return playerOnMove.pourOutBowl(index);
}

template<int N> 
bool Game<N>::eatBowl(int index) {
    int points = playerOnMove.eatBowl(index);
    if(points == -1) {
        return false;
    }
    playerOnMove.checkIfWon();
    return true;
}

template<int N> 
bool Game<N>::useSpoon() {

}
    
} // namespace Noodle
