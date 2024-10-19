#ifndef NODE_HPP
#define NODE_HPP

#include <algorithm>

enum Color {red, black};

class Node {
    public:
        int value;
        Node* left;
        Node* right;
        Node* parent;
        Color color;
    public:
        Node(int value);
        ~Node();
};

#endif