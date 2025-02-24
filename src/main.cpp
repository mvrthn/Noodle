#include <iostream>
#include <unordered_map>

#include "game.hpp"


int main() {
    Noodle::Buffer buffer;  
    Noodle::Game<3> game(buffer);
    int x;
    std::unordered_map<int, std::string> map = {

        {128, "POOL"},
        {129, "PLAYER"},
        {130, "HAND"},
        {131, "BOWL"},
        {132, "ADD"},
        {133, "DEL"},
        {134, "CLR"},
        {135, "OFF"}
    };
    while(buffer >> x) {
        if(map.contains(x)) {
            std::cout << map[x];
        }
        else {
            std::cout << x;
        }
        std::cout << '\n';
    } 
    return 0;
}