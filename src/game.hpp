#pragma once 


#include "deck.hpp"
#include "pool.hpp"
#include "player.hpp"
#include "types.hpp"
#include "buffer.hpp"


namespace Noodle {

template<int N>
class Game {
public:
    Game(Buffer&);

    Status drawCardFromDeck();
    Status drawCardFromPool(int);
    Status redrawPool();
    Status addCardToBowl(int, int);
    Status pourOutBowl(int);
    Status eatBowl(int);
    Status useSpoon(int, int, bool, int, int);
    Status discardCardFromHand(int);

    const Array<Pool::Size>& getDataFromPool() const;
    const Array<Hand::MaxSize>& getDataFromHand(int) const;
    const Array<Bowl::Size>& getDataFromBowl(int, int) const;
    
private:
    Deck deck;
    Pool pool;
    Player players[N];
    Turn<N> turn = Turn<N>(players);
    Buffer& buffer;

private:
    Status endMove();
};

} // namespace Noodle
