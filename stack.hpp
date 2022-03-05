#ifndef __stack__
#define __stack__

#include <cassert>
#include <vector>
#include <iostream>

template <typename T>
class Stack {
protected:
    std::vector<T> _storage;
    size_t _head;

public:
    // Initialize a stack with the specified capacity
    Stack(size_t capacity) : _storage(capacity), _head{0} {}

    // Access the value at the top of the stack
    T& top() { assert(_head > 0) ; 
    std::cout << _storage[_head-1] << std::endl;
    return _storage[_head-1]; }

    // Const-access the value at the top of the stack
    const T& top() const { assert(_head > 0) ;
        std::cout << _storage[_head-1] << std::endl;
        return _storage[_head-1]; }

    // Copy a value to the top of the stack
    void push(const T& x)
    {   
        std::cout << _head << ", " << _storage.size() << x << std::endl;
        assert(_head < _storage.size());
        _storage[_head++] = x;
    }

    // Move a value to the top of the stack (optional)
    void push(T&& x)
    {
        assert(_head < _storage.size());
        _storage[_head++] = std::move(x);
    }

    // Pop the value at the top of the stack
    void pop()
    {
        assert(_head >= 1);
        std::cout<< _head << std::endl;
        --_head;
    }

    // Check if the stack is empty
    bool empty() const { return _head == 0; }

    // Check if the stack is full
    bool full() const { return _head == _storage.size(); }
};

#endif  // __stack__