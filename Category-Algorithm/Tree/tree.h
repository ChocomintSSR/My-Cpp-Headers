#ifndef _TREE_H_
#define _TREE_H_

#include <iostream>
#include <bitset>

namespace chocomint
{
    using std::bitset;
    using std::cout;

    class tree_node
    {
    private:
        int data;
        tree_node *left;
        tree_node *right;
        tree_node *parent;

    public:
        tree_node() : left(NULL), right(NULL), parent(NULL), data(0){};
        tree_node(int d) : left(NULL), right(NULL), parent(NULL), data(d){};
    };

    class binary_tree
    {
    public:
        tree_node *head = new tree_node;

        binary_tree() : head(NULL){};

        template <int N>
        void add_left(bitset<N> &node);
        template <int N>
        void add_right(bitset<N> &node);

        ~binary_tree() { delete head; };
    };

    template <int N>
    void binary_tree::add_left(bitset<N> &node)
    {
        tree_node *current;
        current = head;
    }

    template <int N>
    void binary_tree::add_right(bitset<N> &node)
    {
    }
}

#endif