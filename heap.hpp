#ifndef __heap__
#define __heap__

#include <cassert>
#include <utility>
#include <vector>

#include "binary_tree_complete.hpp"

template <typename V>
using default_comparison_t = std::greater<V>;

template <typename T, typename C>
void heap_sift_up(T&& tree, C compare)
{
    auto parent = tree->parent();
    if (!parent) return;
    if (compare(tree->value(), parent->value()))
        std::swap(tree->value(), parent->value());
    heap_sift_up(parent, compare);
}

template <typename T, typename C>
void heap_sift_down(T&& tree, C compare)
{
    auto child = tree->left();
    auto other = tree->right();
    if (!child ||
        (other && compare(other->value(), child->value()))) {
        child = other;
    }
    if (!child) return;
    if (compare(child->value(), tree->value())) {
        std::swap(child->value(), tree->value());
    }
    heap_sift_down(child, compare);
}

template <typename V, typename C = default_comparison_t<V>>
void build_heap(std::vector<V>& storage, C compare = C{})
{
    for (ssize_t i = (ssize_t)storage.size() / 2 - 1; i >= 0; --i) {
        heap_sift_down(
            CompleteBT<V>{&storage, (size_t)i, storage.size()},
            compare);
    }
}

template <typename V, typename C = default_comparison_t<V>>
void heap_sort(std::vector<V>& storage, C compare = C{})
{
    build_heap(storage, compare);
    for (size_t back = storage.size() - 1; back >= 1; --back) {
        std::swap(storage[0], storage[back]);
        heap_sift_down(CompleteBT<V>{&storage, 0, back}, compare);
    }
}

#endif /* __heap__ */
