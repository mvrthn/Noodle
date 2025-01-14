#pragma once 


#include "card.hpp"


namespace Noodle {

template<int Size>
class Array {
public:
    Array(int n): Size(n) {};

    void insert(Card*, int);
    void push(Card*);

    Card* remove(int);
    Card* pop();

    void clear();
    void update();

    int size() const;
    int len() const;
    bool empty() const;

    const Card* operator[](int i) const;

private:
    Card* cards[Size] = {nullptr};
    int length = 0;
};

}