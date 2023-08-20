#ifndef NOODLE_SCREEN_H
#define NOODLE_SCREEN_H


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


#endif //NOODLE_SCREEN_H