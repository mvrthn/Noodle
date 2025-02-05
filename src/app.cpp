#include "app.hpp"


namespace Noodle {

template<int N>
void App<N>::run() {
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.display();
    }
}

template class App<3>;
template class App<4>;
template class App<5>;

} // namespace Noodle
