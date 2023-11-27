#ifndef NOODLE_PLAYER_H
#define NOODLE_PLAYER_H


#include <vector>
#include "Bowl.hpp"
#include "Deck.hpp"

class Player {
public:
    Player(): spoons(2), score(0) {}

    Bowl& getBowl(int);
    Bowl* getBowls();
    int getHandSize();
    std::vector<Card*>& getHand();
    int getScore();

    void addToHand(Card*);
    void removeFromHand(int);
    
    bool addCardToBowl(int, int, char*);
    bool drawCard(Deck*, bool, int, char*);
    bool replaceTable(Deck*, char*);
    bool eatBowl(int, char*);
    bool pourOutBowl(int, char*);
    bool useSpoon(Player*, int, char*);
    bool useTakenCard(Player*, int, char*);
private:
    Bowl bowls[3];
    std::vector<Card*> hand;
    int spoons;
    int score;
};


#endif //NOODLE_PLAYER_H