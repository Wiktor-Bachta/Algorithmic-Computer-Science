#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "Tree.hpp"
#include "Node.hpp"

class RBTree : public Tree
{
private:
public:
    void insertNode(int value, double &comparisons, double &pointer_operations);
    void deleteNode(int value, double &comparisons, double &pointer_operations);

private:
    void fixDelete(Node *x, Node *xParent, double &pointer_operations);
    void leftRotate(Node *x, double &pointer_operations);
    void rightRotate(Node *x, double &pointer_operations);
    void fixInsert(Node *k, double &pointer_operations);
    void insertNode(Node *node, Node *&root, double &comparisons, double &pointer_operations);
    void deleteNode(int value, Node *&root, double &comparisons, double &pointer_operations);
};

#endif