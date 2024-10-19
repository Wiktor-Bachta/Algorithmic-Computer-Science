#ifndef BSTREE_HPP
#define BSTREE_HPP

#include "Tree.hpp"
#include "Node.hpp"

class BSTree : public Tree
{
public:
    void insertNode(int value, double &comparisons, double &pointer_operations);
    void deleteNode(int value, double &comparisons, double &pointer_operations);

private:
    void insertNode(Node *node, Node *&root, double &comparisons, double &pointer_operations);
    void deleteNode(int value, Node *&root, double &comparisons, double &pointer_operations);
};

#endif