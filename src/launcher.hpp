#pragma once


#include <SFML/Graphics.hpp>



namespace Noodle {
    
class Launcher {
public:
    int run();

private:
    void joinGame();
    void createGame();
};

} // namespace Noodle
