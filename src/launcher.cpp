#include "launcher.hpp"

#include "console.hpp"


namespace Noodle {

int Launcher::run() {
    Console console;

    console.add("Join Game");
    console.add("Create Game");
    console.add("Exit");

    console.display();

    int selected = console.listen();

    if(selected == 0) {
        joinGame();
    }
    else if(selected == 1) {
        createGame();
    }

    return 0;
}

void Launcher::joinGame() {
    Console::write("Joining game...");
}

void Launcher::createGame() {
    Console console;

    console.add("3 Players");
    console.add("4 Players");
    console.add("5 Players");

    console.display();

    int selected = console.listen();
}
    
} // namespace Noodle
