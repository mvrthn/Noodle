#pragma once


#include "game.hpp"


namespace Noodle {

template<int N>
class App {
public:
    void run();

private:
    Game<N> game;
};

} // namespace Noodle