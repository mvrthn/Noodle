#pragma once

#include "Player.hpp"
#include "Screen.hpp"

class Game {
public:
    Game(int, bool);
    ~Game();

    void preset();
    void run();
private:
    int numOfPlayers;
    Player* players;
    Deck* deck;
    bool advancedMove;
    char* errMsg;
    Screen* screen;
};