#include <iostream>

#include "game.hpp"


int main() {
    Noodle::Buffer buffer;  
    Noodle::Game<3> game(buffer);
    int x;
    while(buffer >> x) {
        std::cout << x << '\n';
    } 
    return 0;
}