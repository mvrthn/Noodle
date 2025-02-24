#include <vector>
#include <iostream>
#include <conio.h>


class Console {
public:
    static void write(const std::string&);

    void add(const std::string&);
    void clear();
    void display();
    int listen();

private:
    std::vector<std::string> lines;
    int selected = 0;
};