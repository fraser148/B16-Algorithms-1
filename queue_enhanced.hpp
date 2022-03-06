#ifndef __Equeue__
#define __Equeue__

#include <cassert>
#include <vector>
#include <iostream>
#include "queue.hpp"

template <typename T>
class Dequeue : public Queue<T> {
public:
    Dequeue(size_t capacity) : Queue<T>::Queue(capacity) {};
    
    // Copy an element at the back of the queue
    void enqueue_front(const T& value) { _enqueue_front(value); }

    // Move an element at the back of the queue
    void enqueue_front(T&& value) { _enqueue_front(std::move(value)); }

    // Remove the element at the front of the queue
    void dequeue_front() {
        assert(Queue<T>::_size >= 1);
        Queue<T>::_size--;
        Queue<T>::_position++;
        if (Queue<T>::_position >= Queue<T>::_storage.size()) {
            Queue<T>::_position -= Queue<T>::_storage.size();
        }
    }

        // Access the element at the front of the queue
    T& back() { return Queue<T>::_storage[_end()]; }

    // Const-access the element at the front of the queue
    const T& back() const { return Queue<T>::_storage[_end()]; }

private:
    template <typename Q>
    void _enqueue_front(Q&& x)
    {   
        assert(Queue<T>::_size < Queue<T>::_storage.size());
        Queue<T>::_storage[_front()] = std::forward<Q>(x);
        Queue<T>::_size++;
    }
protected:
    size_t _front() const {
        assert(Queue<T>::_size >= 0);
        auto index = Queue<T>::_position + Queue<T>::_size + 1;
        if (index >= Queue<T>::_storage.size()) {
            index -= Queue<T>::_storage.size();
        }
        return index;
    }

    size_t _end() const {
        auto index = Queue<T>::_position + 1;
        if (index >= Queue<T>::_storage.size()) {
            index -= Queue<T>::_storage.size();
        }
        return index;
    }

};


#endif  // __Equeue__