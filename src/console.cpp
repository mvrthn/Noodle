#include "console.hpp"


void Console::write(const std::string& str) {
    std::cout << str << "\n";
}

void Console::add(const std::string& str) {
    lines.push_back(' ' + str + '\n');
}

void Console::clear() {
    lines.clear();
}

void Console::display() {
    system("cls");
    for(int i = 0; i < lines.size(); i++) {
        if(i == selected) {
            std::cout << '>';
        }
        else {
            std::cout << ' ';
        }
        std::cout << lines[i];
    }
}

int Console::listen() {
    while(true) {
        int c = _getch();
        if(c == 13) {
            return selected;
        }
        if(c == 0 || c == 224) {
            switch(_getch()) {
                case 72:
                    selected = selected > 0 ? selected - 1 : lines.size() - 1;
                    display();
                    break;
                case 80:
                    selected = selected < lines.size() - 1 ? selected + 1 : 0;
                    display();
                    break;
            }
        }
    }
}