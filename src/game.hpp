#pragma once 


#include "deck.hpp"
#include "pool.hpp"
#include "player.hpp"
#include "types.hpp"


namespace Noodle {

template<int N>
class Game {
public:
    ReturnType drawCardFromDeck();
    ReturnType drawCardFromPool(int);
    ReturnType redrawPool();
    ReturnType addCardToBowl(int, int);
    ReturnType pourOutBowl(int);
    ReturnType eatBowl(int);
    ReturnType useSpoon();
    
private:
    Deck deck;
    Pool pool;
    Player players[N];
    Turn<N> turn = Turn<N>(players);

private:
    ReturnType endMove(bool, bool);
    ReturnType endMove(bool);
    ReturnType endMove();
};

} // namespace Noodle
