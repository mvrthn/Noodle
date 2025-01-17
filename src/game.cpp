#include "game.hpp"


namespace Noodle {

template<int N> 
ReturnType Game<N>::drawCardFromDeck() {
    Card* card = deck.drawCard();
    if(!card) {
        return endMove(true);
    }
    turn.playerOnMove.addToHand(card);
    return endMove();
}

template<int N> 
ReturnType Game<N>::drawCardFromPool(int index) {
    Card* card = pool.remove(index);
    if(!card) {
        return endMove(true);
    }
    turn.playerOnMove.addToHand(card);
    Card* newCard = deck.drawCard();
    if(newCard) {
        pool.add(newCard);
    }
    return endMove();
}

template<int N> 
ReturnType Game<N>::redrawPool() {
    pool.clear();
    for(int i = 0; i < 4; i++) {
        Card* card = deck.drawCard();
        if(!card) {
            return endMove(true);
        }
        pool.add(card);
    }
    return endMove();
}

template<int N> 
ReturnType Game<N>::addCardToBowl(int cardIndex, int bowlIndex) {
    Card* card = turn.playerOnMove.removeFromHand(cardIndex);
    if(!card) {
        return endMove(true);
    }
    if(turn.playerOnMove.addToBowl(bowlIndex, card)) {
        turn.playerOnMove.updateHand();
        return endMove();
    }
    turn.playerOnMove.addToHand(card);
    return endMove(true);
}

template<int N> 
ReturnType Game<N>::pourOutBowl(int index) {
    return endMove(!turn.playerOnMove.pourOutBowl(index));
}

template<int N> 
ReturnType Game<N>::eatBowl(int index) {
    int points = turn.playerOnMove.eatBowl(index);
    if(points == -1) {
        return endMove(true);
    }
    return endMove(false, turn.playerOnMove.checkIfWon());
}

template<int N> 
ReturnType Game<N>::useSpoon(int fromPlayer, int fromBowl, bool toHand, int toPlayer, int toBowl) {
    Card* card = players[fromPlayer].removeFromBowl(fromBowl);
    if(!card) {
        return endMove(true);
    }
    if(toHand) {
        turn.playerOnMove.addToHand(card);
        return endMove(false);
    }
    if(players[toPlayer].addToBowl(toBowl, card)) {
        return endMove(false);
    }
    players[fromPlayer].addToBowl(fromBowl, card);
    return endMove(true);
}

template<int N>
ReturnType Game<N>::discardCardFromHand(int index) {
    turn.playerOnMove.removeFromHand(index);
    return endMove();
}

template<int N>
ReturnType Game<N>::endMove(bool failed, bool gameEnd) {
    if(failed) {
        return FAILED;
    }
    if(gameEnd) {
        return SUCCESS_GAME_END;
    }
    turn.move();
    if(!turn.isFinished()) {
        return SUCCESS_NO_EVENT;
    }
    if(!turn.playerOnMove.handIsValid()) {
        return SUCCESS_HAND_NOT_VALID;
    }
    turn.next(players);
    return SUCCES_TURN_END;
}

template<int N>
ReturnType Game<N>::endMove(bool failed) { return endMove(failed, false); }

template<int N>
ReturnType Game<N>::endMove() { return endMove(false, false); }

template class Game<3>;
template class Game<4>;
template class Game<5>;
    
} // namespace Noodle
