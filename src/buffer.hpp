#pragma once


#include <string>


namespace Noodle {

class Buffer {
public:
    Buffer& operator<<(int);
    Buffer* operator>>(int&);

private:
    static constexpr int SlotSize = 64;
    int data[SlotSize];
    int front = 0;
    int back = 0;
};

} // namespace Noodle
