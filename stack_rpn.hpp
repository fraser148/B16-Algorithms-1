#include "stack.hpp"

template <typename T>
void multiplies(Stack<T>& s) {
    T end = s.top();
    s.pop();
    T start = s.top();
    s.pop();
    s.push(start*end);
}

template <typename T>
void plus(Stack<T>& s) {
    T end = s.top();
    s.pop();
    T start = s.top();
    s.pop();
    s.push(start+end);
}

template <typename T>
Stack<T>& Stack<T>::operator << (const T& x) {
    
}
