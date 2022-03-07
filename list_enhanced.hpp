#ifndef __Elist__
#define __Elist__

#include <cassert>
#include <vector>
#include <memory>
#include <iostream>

template <typename T>
struct Node {
    T value;
    std::unique_ptr<Node<T>> next;

    Node() : value{}, next{nullptr} {}
    Node(const T& value, std::unique_ptr<Node<T>> next)
        : value{value}, next{std::move(next)}
    {
    }
};

template <typename T>
Node<T>* list_insert_after(Node<T>* node, const T& value)
{
    node->next =
        std::make_unique<Node<T>>(value, std::move(node->next));
    return node->next.get();
}

template <typename T>
void list_delete_after(Node<T>* node)
{
    Node<T>* temp = node;
    temp = temp->next.get();
    node->next = std::unique_ptr<Node<T>>(std::move(temp->next));
}

template <typename T, typename F>
Node<T>* list_find_predecessor(Node<T>* node, F predicate)
{
    for (; node && node->next; node = node->next.get()) {
        if (predicate(node->next->value)) return node;
    }
    return nullptr;
}

template <typename T>
std::vector<T> list_to_vector(const Node<T>& node)
{
    std::vector<T> v;
    for (Node<T>* current = node.next.get(); current;
         current = current->next.get()) {
        v.push_back(current->value);
    }
    return v;
}

#endif  // __Elist__

