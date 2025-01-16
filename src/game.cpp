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
ReturnType Game<N>::useSpoon() {

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
    ReturnType rt;
    if(turn.playerOnMove.handIsValid()) {
        rt = SUCCES_TURN_END;
    }
    else {
        rt = SUCCESS_HAND_NOT_VALID;
    }
    turn.next(players);
    return rt;
}

template<int N>
ReturnType Game<N>::endMove(bool failed) { return endMove(failed, false); }

template<int N>
ReturnType Game<N>::endMove() { return endMove(false, false); }
    
} // namespace Noodle
