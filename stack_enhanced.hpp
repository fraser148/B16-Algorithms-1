#ifndef __Estack__
#define __Estack__

#include "stack.hpp"
#include <iostream>

template <typename T>
class StackEnhanced : public Stack<T> {
public:
    StackEnhanced(size_t capacity) : Stack<T>::Stack(capacity) {};

    void clear() {
        while(Stack<T>::_storage.empty() != 0) {
            Stack<T>::pop();
        }
    };
};

template <typename T>
auto operator<<(StackEnhanced<T> s, const T& x) {
    s.Stack<T>::push(x);
    return s;
}

#endif  // __Estack__