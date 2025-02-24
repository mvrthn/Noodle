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
    static void checkIfInBounds(int);
    static constexpr int BowlNum = 3;
    static constexpr int SpoonNum = 2;

private:
    Hand hand;
    Bowl bowls[BowlNum];
    int spoons = SpoonNum;
    int score = 0;
    int eatenBowls = 0;
};

} // namespace Noodle