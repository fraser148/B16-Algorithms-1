#ifndef __Estack__
#define __Estack__

#include "stack.hpp"
#include <iostream>

template <typename T>
class StackEnhanced : public Stack<T> {
public:
    StackEnhanced(size_t capacity) : Stack<T>::Stack(capacity) {};

    void clear() {
        while(Stack<T>::empty() == 0) {
            Stack<T>::pop();
        }
    };

    StackEnhanced<T>& operator<<(const T& x) {
        Stack<T>::push(x);
        return *this;
    };

};

//template <typename T>

#endif  // __Estack__