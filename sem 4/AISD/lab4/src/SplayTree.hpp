#ifndef SPLAYTREE_HPP
#define SPLAYTREE_HPP

#include "Tree.hpp"
#include "Node.hpp"

class SplayTree : public Tree
{
public:
    void insertNode(int value, double &comparisons, double &pointer_operations);
    void deleteNode(int value, double &comparisons, double &pointer_operations);

private:
    void splay(Node *x, double &pointer_operations);
    void leftRotate(Node *x, double &pointer_operations);
    void rightRotate(Node *x, double &pointer_operations);
    void insertNode(Node *node, Node *&root, double &comparisons, double &pointer_operations);
    void deleteNode(int value, Node *&root, double &comparisons, double &pointer_operations);
};

#endif
