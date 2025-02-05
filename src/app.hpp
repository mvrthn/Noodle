#pragma once


#include "SFML/Graphics.hpp"

#include "game.hpp"


constexpr int defaultW = 1600;
constexpr int defaultH = 900;


namespace Noodle {

template<int N>
class App {
public:
    void run();

private:
    sf::Window window = sf::Window({defaultW, defaultH}, "Noodle", sf::Style::Close);
    Game<N> game;
};

} // namespace Noodle