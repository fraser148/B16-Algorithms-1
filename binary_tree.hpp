#ifndef __binary_tree__
#define __binary_tree__

#include <memory>
#include <utility>

// A class representing a basic binary tree
template <typename V>
struct BinaryTree {
    V _value;
    std::unique_ptr<BinaryTree<V>> _left;
    std::unique_ptr<BinaryTree<V>> _right;

    V& value() { return _value; }
    const V& value() const { return _value; }
    BinaryTree<V>* left() const { return _left.get(); }
    BinaryTree<V>* right() const { return _right.get(); }
};

// A helper function to build a binary tree
template <typename V>
std::unique_ptr<BinaryTree<V>>
make_binary_tree(const V& value,
                std::unique_ptr<BinaryTree<V>> left,
                std::unique_ptr<BinaryTree<V>> right)
{
    return std::unique_ptr<BinaryTree<V>> {
        new BinaryTree<V>{value, std::move(left), std::move(right)}};
}

#endif  // __binary_tree__