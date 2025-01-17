#include "array.hpp"

#include <cassert>


namespace Noodle {

template<int Size>
void Array<Size>::insert(Card* card, int i) {
    assert(i >= 0 && i < Size);
    if(cards[i]) {
        assert(false && "insert(): slot occupied");
    } 
    length++;
    cards[i] = card;
}

template <int Size>
void Array<Size>::push(Card* card) {
    for(int i = 0; i < Size; i++) {
        if(cards[i]) {
            continue;
        }
        cards[i] = card;
        length++;
        return;
    } 
    assert(false && "push(): no free slot in array");
}

template <int Size>
Card *Array<Size>::remove(int i) {
    assert(i >= 0 && i < Size);
    Card* card = cards[i];
    if(!card) {
        assert(false && "remove(): no element at given index");
    }
    length--;
    cards[i] = nullptr;
    return card;
}

template <int Size>
Card *Array<Size>::pop() {
    for(int i = Size - 1; i >= 0; i++) {
        if(!cards[i]) {
            continue;
        }
        Card* card = cards[i];
        cards[i] = nullptr;
        length--;
        return card; 
    }
    assert(false && "pop(): no elements in array");
}

template <int Size>
void Array<Size>::clear() {
    for(int i = 0; i < Size; i++) {
        cards[i] = nullptr;
    }
    length = 0;
}

template <int Size>
void Array<Size>::update() {
    int idx = 0;
    for(int i = 0; i < Size; i++) {
        if(!cards[i]) {
            continue;
        }
        if(idx == i) {
            idx++;
            continue;
        }
        cards[idx++] = cards[i];
    }
    for(; idx < Size; idx++) {
        cards[idx] = nullptr;
    }
}

template<int Size>
int Array<Size>::size() const {
    return Size;
}

template<int Size>
int Array<Size>::len() const {
    return length;
}

template <int Size>
bool Array<Size>::empty() const {
    return length > 0;
}

template<int Size>
const Card* Array<Size>::operator[](int i) const {
    assert(i >= 0 && i <= Size);
    assert(cards[i]);
    return cards[i];
}

template class Array<4>;
template class Array<5>;
template class Array<7>;

} // namespace Noodle
