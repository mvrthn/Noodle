#pragma once 


#include "deck.hpp"
#include "pool.hpp"
#include "player.hpp"


namespace Noodle {

template<int N>
class Game {
public:
    bool drawCardFromDeck();
    bool drawCardFromPool(int);
    bool redrawPool();
    bool addCardToBowl(int, int);
    bool pourOutBowl(int);
    bool eatBowl(int);
    bool useSpoon();
    
private:
    Deck deck;
    Pool pool;
    Player players[N];
    Player& playerOnMove = players[0];
    int playerIndex = 0;
};

} // namespace Noodle
