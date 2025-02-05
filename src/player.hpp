#pragma once 


#include "card.hpp"
#include "bowl.hpp"
#include "hand.hpp"


namespace Noodle {
    
class Player {
public:
    void addToHand(Card*);
    Card* removeFromHand(int);
    bool handIsValid() const;
    void updateHand();

    bool addToBowl(int, Card*);
    Card* removeFromBowl(int);

    int eatBowl(int);
    bool pourOutBowl(int);

    bool useSpoon();
    bool checkIfWon() const;

    const Array<Bowl::Size>& getDataFromBowl(int) const;
    const Array<Hand::MaxSize>& getDataFromHand() const;

private:
    Hand hand;
    Bowl bowls[3];
    int spoons = 2;
    int score = 0;
    int eatenBowls = 0;

private:
    void checkIfInBounds(int) const;
};

} // namespace Noodle