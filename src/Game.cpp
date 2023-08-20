#include "Game.hpp"
#include "Player.hpp"
#include "Deck.hpp"

Game::Game(int numOfPlayers, bool advancedMode) {
    if(numOfPlayers < 3) this->numOfPlayers = 3;
    else if(numOfPlayers > 5) this->numOfPlayers = 5;
    else this->numOfPlayers = numOfPlayers;
    this->players = new Player[this->numOfPlayers];
    this->deck = new Deck(advancedMode);
    this->advancedMove = advancedMode;
    this->errMsg = new char[64];
    this->screen = new Screen(players, numOfPlayers, deck, errMsg);
}

Game::~Game() {
    delete[] players;
    delete deck;
    delete[] errMsg;
}

void Game::preset() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < numOfPlayers; j++) {
            players[j].addToHand(deck->getCardFromStack(errMsg));
        }
    }
    deck->replaceTable(errMsg);
}

void Game::run() {
    int turn = 0;
    while(true) {
        int playerIndex = turn % numOfPlayers;
        screen->update(playerIndex);
        turn++;
        if(turn == 1) {
            break;
        }
    }
}