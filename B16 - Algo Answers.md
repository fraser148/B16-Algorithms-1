# B16 - Algorithms 1

Due: 07/03/2022 18:00
Status: In Progress
Tutorial Date: 09/03/2022 16:00

[https://github.com/fraser148/B16-Algorithms-1.git](https://github.com/fraser148/B16-Algorithms-1.git)

# Linear-time Sorting

## Radix Sort

This has a time complexity of $O(k\cdot n)$ where $k$ is the number of digits in each number and $n$  is the number of numbers.

Each step requires just a single pass over the data, since each item can be placed in its bucket without comparison with any other element.

This is a non-comparative algorithm and simply puts the current digit in the correct pocket. The pockets are then replaced into the array.

```bash
Before sorting: [1, 19, 2, 9, 12, 18, 4, 8, 5, 6, 17, 10, 11, 14, 16, 15, 7, 3, 13, 20]
After sorting: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
```

# Arrays

## Complexity of `ArrayInsert`

The time complexity of inserting an element into an array at the end is just $O(1)$, however inserting in the middle or start has a time complexity of $O(n)$

## Deleting elements from an array

The function takes both the array and the index of the element to be deleted. It is a template function so that the vector can be of any datatype.

```cpp
template <typename T>
void array_delete(std::vector<T>& A, const std::size_t index) {
    assert(index <= A.size());
    int end = (A.size()-1);
    for (int i = index; i != end; i++) {
        A[i] = A[i + 1];
    }
    A.pop_back();
}
```

```bash
Initial array: [0, 1, 2, 79, 4.4, 4]
Array after deleting element at position 0: [1, 2, 79, 4.4, 4]
Array after deleting element at position 0: [2, 79, 4.4, 4]
Array after deleting element at position 0: [79, 4.4, 4]
Array after deleting element at position 0: [4.4, 4]
Array after deleting element at position 0: [4]
Array after deleting element at position 0: []
```

# Stacks

## `EnhancedStack` Class

Making the `StackEnhanced` class a child of the `Stack` class. We can add both the clear the overloaded operator `<<`

```cpp
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
```

## Reverse Polish Calculator

E.g. $2\:2\:3\:+\:\times$ is the same as $2\times(2+3)=10$:

```cpp
template <typename T>
void plus(Stack<T>& s) {
    T end = s.top();
    s.pop();
    T start = s.top();
    s.pop();
    s.push(start+end);
}
```

I did not implement the advanced case.

# Queues

## Enhanced Queue Class

I developed the `EnhancedQueue` class successfully however I am not happy with how many times I needed to use `Queue<T>::` to access the variables and methods of the child class. I cannot imagine that this is best practise. Maybe I could have used “getter” and “setter” methods in the `Queue` class however I am not sure that we should edit it. Below is the `EnhancedQueue` class:

```cpp
template <typename T>
class Dequeue : public Queue<T> {
public:
    Dequeue(size_t capacity) : Queue<T>::Queue(capacity) {};
    
    // Copy an element at the front of the queue
    void enqueue_front(const T& value) { _enqueue_front(value); }

    // Move an element at the front of the queue
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

    // Access the element at the back of the queue
    T& back() { return Queue<T>::_storage[_end()]; }

    // Const-access the element at the back of the queue
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
```

The usage of both the `front()` and the `end()` methods also seems slightly too complicated. If I were to create the class from scratch, I would have two pointers, one at the front and one at the back of the queue.

<aside>
✅ I did however generate the correct result.

</aside>

```bash
Enqueued front 0 1 2
Dequeued front 2 1 0
Enqueued back  0 1 2
Dequeued back  2 1 0
Enqueued front 0 1 2
Dequeued front 2 1 0
Enqueued back  0 1 2
Dequeued back  2 1 0
Enqueued front 0 1 2
Dequeued front 2 1 0
Enqueued back  0 1 2
Dequeued back  2 1 0
```