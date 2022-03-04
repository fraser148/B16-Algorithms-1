#ifndef __binary_search_tree__
#define __binary_search_tree__

#include "binary_tree.hpp"

template <typename V>
std::unique_ptr<BinaryTree<V>>
bst_insert(std::unique_ptr<BinaryTree<V>> tree, const V& value)
{
    if (!tree) return make_binary_tree(value, {}, {});
    if (value <= tree->value()) {
        tree->_left = bst_insert(std::move(tree->_left), value);
    } else {
        tree->_right = bst_insert(std::move(tree->_right), value);
    }
    return tree;
}

template <class T, typename V>
T bst_search(const T& tree, const V& value)
{
    if (!tree || value == tree->value()) return tree;
    if (value < tree->value()) return bst_search(tree->left(), value);
    auto other = bst_search(tree->right(), value);
    return other ? other : tree;
}

#endif  // __binary_search_tree__
