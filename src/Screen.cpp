#include <iostream>
#include <cstdlib>
#include "Screen.hpp"

Screen::Screen(Player* players, int numOfPlayers, Deck* deck, char* errMsg) {
    this->players = players;
    this->numOfPlayers = numOfPlayers;
    this->errMsg = errMsg;
    this->table = deck->getTable();
    bowls = new Bowl*[3 * numOfPlayers];
    for(int i = 0; i < numOfPlayers; i++) {
        int j = 3 * i;
        bowls[j] = players[i].getBowls();
        bowls[j + 1] = bowls[j] + 1;
        bowls[j + 2] = bowls[j] + 2;
    }
}

Screen::~Screen() {
    delete[] bowls;
}

void Screen::update(int x) {
    system("clear");
    for(int i = 0; i < numOfPlayers; i++) {
        std::cout << "Player " << i + 1 << ": ";
        for(int j = 0; j < 3; j++) {
            Card* cards = bowls[3 * i + j]->getCards();
            std::cout << (j ? "          -> " : "-> ");
            if(!cards) std::cout << "\n";
            int k = bowls[3 * i + j]->getTopIndex();
            for(int n = 0; n < k; n++) {
                std::cout << (cards + n)->name() << (n < k - 1 ? ", " : "\n");
            }
        }
        std::cout << "\n";
    }
    std::cout << "Table: ";
    for(int i = 0; i < 4; i++) {
        std::cout << (*(table + i) ? (*(table + i))->name() : "[]") << (i < 3 ? ", " : "\n");
    }
    std::cout << "Your hand: ";
    int n = players[x].getHandSize();
    Card* hand = players[x].getHand();
    for(int i = 0; i < n; i++) {
        std::cout << (hand + i)->name() << (i < n - 1 ? ", " : "\n");
    }
}