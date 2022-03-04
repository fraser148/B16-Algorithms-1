#ifndef __binary_tree_complete__
#define __binary_tree_complete__

#include <vector>
#include <limits>

// Wraps a vector in a complete binary tree
template <typename V>
struct CompleteBT
{
    std::vector<V>* _storage;
    size_t _root;
    size_t _size;

    CompleteBT<V>(std::vector<V>* storage) :
    _storage{storage}, _root{0}, _size{storage->size()} {}

    CompleteBT<V>(std::vector<V>* storage, size_t root, size_t size) :
    _storage{storage}, _root{root}, _size{size} {}

    CompleteBT<V> subtree(size_t root) const
    {
        return CompleteBT<V>{_storage, root, _size};
    }

    V& value() { return (*_storage)[_root]; }
    const V& value() const { return (*_storage)[_root]; }

    CompleteBT<V> parent() const
    {
        if (_root == 0) return subtree(std::numeric_limits<size_t>::max());
        return subtree((_root - 1) / 2);
    }
    CompleteBT<V> left() const { return subtree(2 * _root + 1); }
    CompleteBT<V> right() const { return subtree(2 * _root + 2); }

    explicit operator bool() const { return _root < _size; }
    CompleteBT<V>* operator->() { return this; }
    const CompleteBT<V>* operator->() const { return this; }
};

#endif  // __binary_tree_complete__