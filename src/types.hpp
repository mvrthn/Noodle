#pragma once 


#include "player.hpp"


namespace Noodle {

enum ReturnType {
    FAILED,
    SUCCESS_NO_EVENT,
    SUCCESS_HAND_NOT_VALID,
    SUCCES_TURN_END,
    SUCCESS_GAME_END,
};

template<int N>
struct Turn {
    int movesLeft = 2;
    int playerIndex = 0;
    Player& playerOnMove;
    Turn(Player (&players)[N]): playerOnMove(players[0]) {}
    inline void next(Player (&players)[N]) {
        movesLeft = 2;
        playerIndex = (playerIndex + 1) % N;
        playerOnMove = players[playerIndex];
    }
    inline void move() { movesLeft--; }
    inline bool isFinished() { return movesLeft == 0; }
};

    
} // namespace Noodle
