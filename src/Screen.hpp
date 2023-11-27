#pragma once

#include "Player.hpp"

class Screen {
public:
    Screen(Player*, int, Deck*, char*);
    ~Screen();
    
    void update(int);
private:
    Player* players;
    int numOfPlayers;
    char* errMsg;
    Bowl** bowls;
    Card** table;
};