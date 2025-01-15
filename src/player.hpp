#pragma once 


#include "card.hpp"
#include "bowl.hpp"
#include "hand.hpp"


namespace Noodle {
    
class Player {
public:
    void addToHand(Card*);
    Card* removeFromHand(int);
    void updateHand();

    bool addToBowl(int, Card*);
    Card* removeFromBowl(int);

    int eatBowl(int);
    bool pourOutBowl(int);

    bool useSpoon();
    bool checkIfWon();

private:
    Hand hand;
    Bowl bowls[3];
    int spoons = 2;
    int score = 0;
    int eatenBowls = 0;

private:
    void checkIfInBounds(int);
};

} // namespace Noodle