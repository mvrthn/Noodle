#include "game.hpp"


namespace Noodle {

template<int N>
Game<N>::Game(Buffer& b): buffer(b) {
    buffer << POOL << ADD;
    for(int i = 0; i < Pool::Size; i++) {
        Card* card = deck.drawCard();
        pool.add(card);
        buffer << i << card->id();
    }

    for(int i = 0; i < N; i++) {
        buffer << PLAYER << i << HAND << ADD;
        for(int j = 0; j < Hand::StartSize; j++) {
            Card* card = deck.drawCard();
            players[i].addToHand(card);
            buffer << card->id();
        }
    } 
}

template<int N> 
Status Game<N>::drawCardFromDeck() {
    Card* card = deck.drawCard();
    if(!card) {
        return FAILED;
    }
    turn.playerOnMove.addToHand(card);
    buffer << PLAYER << turn.playerIndex << HAND << ADD << card->id();
    return endMove();
}

template<int N> 
Status Game<N>::drawCardFromPool(int index) {
    Card* card = pool.remove(index);
    if(!card) {
        return FAILED;
    }
    turn.playerOnMove.addToHand(card);
    Card* newCard = deck.drawCard();
    if(newCard) {
        pool.add(newCard);
    }
    buffer << POOL << ADD << newCard->id() << PLAYER << turn.playerIndex << HAND << ADD << card->id();
    return endMove();
}

template<int N> 
Status Game<N>::redrawPool() {
    pool.clear();
    buffer << POOL;
    for(int i = 0; i < Pool::Size; i++) {
        Card* card = deck.drawCard();
        if(!card) {
            buffer << DEL << i;
            continue;
        }
        pool.add(card);
        buffer << ADD << i << card->id();
    }
    return endMove();
}

template<int N> 
Status Game<N>::addCardToBowl(int cardIndex, int bowlIndex) {
    Card* card = turn.playerOnMove.removeFromHand(cardIndex);
    if(!card) {
        return FAILED;
    }
    if(turn.playerOnMove.addToBowl(bowlIndex, card)) {
        turn.playerOnMove.updateHand();
        return FAILED;
    }
    turn.playerOnMove.addToHand(card);
    buffer << PLAYER << turn.playerIndex << HAND << DEL << cardIndex << BOWL << bowlIndex << ADD << card->id();
    return endMove();
}

template<int N> 
Status Game<N>::pourOutBowl(int index) {
    if(!turn.playerOnMove.pourOutBowl(index)) {
        return FAILED;
    }
    buffer << PLAYER << turn.playerIndex << BOWL << index << CLR;
    return endMove();
}

template<int N> 
Status Game<N>::eatBowl(int index) {
    int points = turn.playerOnMove.eatBowl(index);
    if(points == -1) {
        return FAILED;
    }
    buffer << PLAYER << turn.playerIndex << BOWL << index << OFF << points;
    return turn.playerOnMove.checkIfWon() ? SUCCESS_GAME_END : endMove();
}

template<int N> 
Status Game<N>::useSpoon(int fromPlayer, int fromBowl, bool toHand, int toPlayer, int toBowl) {
    if(!turn.playerOnMove.useSpoon()) {
        return FAILED;
    }
    Card* card = players[fromPlayer].removeFromBowl(fromBowl);
    if(!card) {
        return FAILED;
    }
    if(toHand) {
        buffer << PLAYER << fromPlayer << BOWL << fromBowl << DEL << PLAYER << toPlayer << HAND << ADD << card->id();
        turn.playerOnMove.addToHand(card);
        return endMove();
    }
    if(players[toPlayer].addToBowl(toBowl, card)) {
        buffer << PLAYER << fromPlayer << BOWL << fromBowl << DEL << PLAYER << toPlayer << BOWL << toBowl << ADD << card->id();
        return endMove();
    }
    players[fromPlayer].addToBowl(fromBowl, card);
    return FAILED;
}

template<int N>
Status Game<N>::discardCardFromHand(int index) {
    turn.playerOnMove.removeFromHand(index);
    buffer << PLAYER << turn.playerIndex << HAND << DEL << index;
    return endMove();
}

template<int N>
const Array<Pool::Size>& Game<N>::getDataFromPool() const {
    return pool.getData();
}

template<int N>
const Array<Hand::MaxSize>& Game<N>::getDataFromHand(int playerIndex) const {
    return players[playerIndex].getDataFromHand();
}

template<int N>
const Array<Bowl::Size>& Game<N>::getDataFromBowl(int playerIndex, int bowlIndex) const {
    return players[playerIndex].getDataFromBowl(bowlIndex);
}

template<int N>
Status Game<N>::endMove() {
    turn.move();
    if(!turn.isFinished()) {
        return SUCCESS_NO_EVENT;
    }
    if(!turn.playerOnMove.handIsValid()) {
        return SUCCESS_HAND_NOT_VALID;
    }
    turn.next(players);
    return SUCCESS_TURN_END;
}

template class Game<3>;
template class Game<4>;
template class Game<5>;
    
} // namespace Noodle
