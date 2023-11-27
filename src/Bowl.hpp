#ifndef NOODLE_BOWL_H
#define NOODLE_BOWL_H


#include "Flavor.hpp"

class Bowl {
public:
    Bowl(): cards{}, flavor(nullptr), isEaten(false), topIndex(0), score(0) {};

    inline Card* getCards() {return *cards;}
    inline int getTopIndex() {return topIndex;}
    inline int getScore() {return score;}

    bool addCard(Card*, char*);
    Card* removeCard(char*);
    bool eat(char*);
    bool pourOut(char*);
private:
    Card* cards[5];
    Flavor* flavor;
    bool isEaten;
    short topIndex;
    int score;
};


#endif //NOODLE_BOWL_H