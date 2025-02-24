#include "buffer.hpp"

#include <cassert>

namespace Noodle {

Buffer& Buffer::operator<<(int value) {
    data[back] = value;
    if(++back == SlotSize) {
        back = 0;
    }
    assert(back != front);
    return *this;
}

Buffer* Buffer::operator>>(int& target) {
    if(front == back) 
        return nullptr;
    target = data[front];
    if(++front == SlotSize) {
        front = 0;
    }
    return this;
}
    
} // namespace Noodle
