#pragma once 


#include "player.hpp"


namespace Noodle {

enum Status {
    FAILED,
    SUCCESS_NO_EVENT,
    SUCCESS_HAND_NOT_VALID,
    SUCCESS_TURN_END,
    SUCCESS_GAME_END
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
    inline void move() { if(movesLeft) movesLeft--; }
    inline bool isFinished() { return movesLeft <= 0; }
};

enum Target : int{
    POOL = 128,
    PLAYER,
    HAND,
    BOWL,
    ADD,
    DEL,
    CLR,
    OFF
};
    
} // namespace Noodle
