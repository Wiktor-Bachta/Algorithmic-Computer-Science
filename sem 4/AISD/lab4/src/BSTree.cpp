#include "BSTree.hpp"
#include <iostream>

void BSTree::deleteNode(int value, double &comparisons, double &pointer_operations)
{
    deleteNode(value, root, comparisons, pointer_operations);
}

void BSTree::deleteNode(int value, Node *&root, double &comparisons, double &pointer_operations)
{
    pointer_operations++;
    if (root == nullptr)
    {
        return;
    }
    comparisons += 2;
    if (value < root->value)
    {
        comparisons--;
        deleteNode(value, root->left, comparisons, pointer_operations);
    }
    else if (value > root->value)
    {
        deleteNode(value, root->right, comparisons, pointer_operations);
    }
    else
    {
        pointer_operations += 4;
        if (root->left == nullptr && root->right == nullptr)
        {
            pointer_operations -= 1;
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr)
        {
            pointer_operations++;
            Node *temp = root->right;
            delete root;
            root = temp;
        }
        else if (root->right == nullptr)
        {
            pointer_operations += 2;
            Node *temp = root->left;
            delete root;
            root = temp;
        }
        else
        {
            pointer_operations += 2;
            Node *succesor = root->right;
            while (succesor->left != nullptr)
            {
                pointer_operations += 2;
                succesor = succesor->left;
            }
            root->value = succesor->value;
            deleteNode(succesor->value, root->right, comparisons, pointer_operations);
        }
    }
}

void BSTree::insertNode(int value, double &comparisons, double &pointer_operations)
{
    Node *newNode = new Node(value);
    insertNode(newNode, root, comparisons, pointer_operations);
}

void BSTree::insertNode(Node *node, Node *&root, double &comparisons, double &pointer_operations)
{
    pointer_operations++;
    if (root == nullptr)
    {
        pointer_operations++;
        root = node;
        return;
    }
    comparisons++;
    if (node->value < root->value)
    {
        insertNode(node, root->left, comparisons, pointer_operations);
    }
    else
    {
        insertNode(node, root->right, comparisons, pointer_operations);
    }
}