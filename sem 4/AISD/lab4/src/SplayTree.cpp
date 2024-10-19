#include "SplayTree.hpp"

void SplayTree::insertNode(int value, double &comparisons, double &pointer_operations)
{
    Node *newNode = new Node(value);
    insertNode(newNode, root, comparisons, pointer_operations);
    splay(newNode, pointer_operations);
}

void SplayTree::insertNode(Node *node, Node *&root, double &comparisons, double &pointer_operations)
{
    pointer_operations++;
    if (root == nullptr)
    {
        root = node;
        pointer_operations++;
        return;
    }
    comparisons++;
    if (node->value < root->value)
    {
        pointer_operations++;
        if (root->left == nullptr)
        {
            root->left = node;
            node->parent = root;
            pointer_operations += 2;
        }
        else
        {
            insertNode(node, root->left, comparisons, pointer_operations);
        }
    }
    else
    {
        pointer_operations++;
        if (root->right == nullptr)
        {
            root->right = node;
            node->parent = root;
            pointer_operations += 2;
        }
        else
        {
            insertNode(node, root->right, comparisons, pointer_operations);
        }
    }
}

void SplayTree::deleteNode(int value, double &comparisons, double &pointer_operations)
{
    deleteNode(value, root, comparisons, pointer_operations);
}

void SplayTree::deleteNode(int value, Node *&root, double &comparisons, double &pointer_operations)
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
            pointer_operations--;
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr)
        {
            pointer_operations += 2;
            Node *temp = root->right;
            temp->parent = root->parent;
            delete root;
            root = temp;
            splay(root->parent, pointer_operations);
        }
        else if (root->right == nullptr)
        {
            pointer_operations += 3;
            Node *temp = root->left;
            temp->parent = root->parent;
            delete root;
            root = temp;
            splay(root->parent, pointer_operations);
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

void SplayTree::splay(Node *x, double &pointer_operations)
{
    pointer_operations++;
    while (x && x->parent)
    {
        pointer_operations += 8;
        if (!x->parent->parent)
        {
            pointer_operations -= 5;
            if (x->parent->left == x)
            {
                rightRotate(x->parent, pointer_operations);
            }
            else
            {
                leftRotate(x->parent, pointer_operations);
            }
        }
        else if (x->parent->left == x && x->parent->parent->left == x->parent)
        {
            pointer_operations -= 4;
            rightRotate(x->parent->parent, pointer_operations);
            rightRotate(x->parent, pointer_operations);
        }
        else if (x->parent->right == x && x->parent->parent->right == x->parent)
        {
            pointer_operations -= 2;
            leftRotate(x->parent->parent, pointer_operations);
            leftRotate(x->parent, pointer_operations);
        }
        else if (x->parent->left == x && x->parent->parent->right == x->parent)
        {
            rightRotate(x->parent, pointer_operations);
            leftRotate(x->parent, pointer_operations);
        }
        else
        {
            leftRotate(x->parent, pointer_operations);
            rightRotate(x->parent, pointer_operations);
        }
    }
}

void SplayTree::leftRotate(Node *x, double &pointer_operations)
{
    Node *y = x->right;
    x->right = y->left;
    if (y->left != nullptr)
    {
        pointer_operations++;
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr)
    {
        root = y;
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
    pointer_operations += 8;
}

void SplayTree::rightRotate(Node *x, double &pointer_operations)
{
    Node *y = x->left;
    x->left = y->right;
    if (y->right != nullptr)
    {
        pointer_operations++;
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr)
    {
        root = y;
    }
    else if (x == x->parent->right)
    {
        x->parent->right = y;
    }
    else
    {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
    pointer_operations += 8;
}