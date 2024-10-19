#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
#include <iostream>

class Tree
{
public:
    Node* root;
public:
    virtual void insertNode(int value, double &comparisons, double &pointer_operations) = 0;
    virtual void deleteNode(int value, double &comparisons, double &pointer_operations) = 0;
    int height();
    int treeSize();
    void printTree();
    Node* minimum(Node *node);
    Tree();
    ~Tree();
    void deleteTree();
private:
    int height(Node* root);
    int treeSize(Node* root);
    void deleteTree(Node* root);
    void printTree(Node *root, int depth, char prefix, char *&left_trace, char *&right_trace);
};

#endif