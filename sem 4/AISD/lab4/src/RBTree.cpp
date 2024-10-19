#include "RBTree.hpp"

void RBTree::leftRotate(Node *x, double &pointer_operations)
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

void RBTree::rightRotate(Node *x, double &pointer_operations)
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

void RBTree::fixInsert(Node *k, double &pointer_operations)
{
    pointer_operations++;
    while (k != root && k->parent->color == red)
    {
        pointer_operations++;
        if (k->parent == k->parent->parent->left)
        {
            pointer_operations += 2;
            Node *u = k->parent->parent->right; // uncle
            if (u != nullptr && u->color == red)
            {
                k->parent->color = black;
                u->color = black;
                k->parent->parent->color = red;
                pointer_operations++;
                k = k->parent->parent;
            }
            else
            {
                pointer_operations++;
                if (k == k->parent->right)
                {
                    pointer_operations++;
                    k = k->parent;
                    leftRotate(k, pointer_operations);
                }
                k->parent->color = black;
                k->parent->parent->color = red;
                rightRotate(k->parent->parent, pointer_operations);
            }
        }
        else
        {
            pointer_operations += 2;
            Node *u = k->parent->parent->left; // uncle
            if (u != nullptr && u->color == red)
            {
                k->parent->color = black;
                u->color = black;
                k->parent->parent->color = red;
                pointer_operations++;
                k = k->parent->parent;
            }
            else
            {
                pointer_operations++;
                if (k == k->parent->left)
                {
                    pointer_operations++;
                    k = k->parent;
                    rightRotate(k, pointer_operations);
                }
                k->parent->color = black;
                k->parent->parent->color = red;
                leftRotate(k->parent->parent, pointer_operations);
            }
        }
        pointer_operations++;
    }
    root->color = black;
}

void RBTree::insertNode(int value, double &comparisons, double &pointer_operations)
{
    Node *newNode = new Node(value);
    insertNode(newNode, root, comparisons, pointer_operations);
}

void RBTree::insertNode(Node *node, Node *&root, double &comparisons, double &pointer_operations)
{
    if (root == nullptr)
    {
        pointer_operations += 2;
        root = node;
        if (root->parent == nullptr)
        {
            root->color = black;
            return;
        }
        if (root->parent->parent == nullptr)
        {
            return;
        }
        fixInsert(root, pointer_operations);
        return;
    }
    node->parent = root;
    pointer_operations++;
    if (node->value < root->value)
    {
        comparisons++;
        insertNode(node, root->left, comparisons, pointer_operations);
    }
    else
    {
        insertNode(node, root->right, comparisons, pointer_operations);
    }
}

void RBTree::fixDelete(Node *x, Node *xParent, double &pointer_operations)
{
    pointer_operations++;
    while (x != root && (x == nullptr || x->color == black))
    {
        pointer_operations += 2;
        if (x == xParent->left)
        {
            pointer_operations++;
            Node *w = xParent->right;
            if (w->color == red)
            {
                w->color = black;
                xParent->color = red;
                leftRotate(xParent, pointer_operations);
                w = xParent->right;
                pointer_operations++;
            }
            pointer_operations += 2;
            if ((w->left == nullptr || w->left->color == black) &&
                (w->right == nullptr || w->right->color == black))
            {
                w->color = red;
                x = xParent;
                xParent = x->parent;
                pointer_operations += 2;
            }
            else
            {
                pointer_operations++;
                if (w->right == nullptr || w->right->color == black)
                {
                    w->left->color = black;
                    w->color = red;
                    rightRotate(w, pointer_operations);
                    w = xParent->right;
                    pointer_operations++;
                }
                w->color = xParent->color;
                xParent->color = black;
                w->right->color = black;
                leftRotate(xParent, pointer_operations);
                x = root;
                pointer_operations++;
            }
        }
        else
        {
            pointer_operations++;
            Node *w = xParent->left;
            if (w->color == red)
            {
                w->color = black;
                xParent->color = red;
                rightRotate(xParent, pointer_operations);
                w = xParent->left;
                pointer_operations++;
            }
            pointer_operations += 2;
            if ((w->right == nullptr || w->right->color == black) &&
                (w->left == nullptr || w->left->color == black))
            {
                w->color = red;
                x = xParent;
                xParent = x->parent;
                pointer_operations += 2;
            }
            else
            {
                pointer_operations++;
                if (w->left == nullptr || w->left->color == black)
                {
                    w->right->color = black;
                    w->color = red;
                    leftRotate(w, pointer_operations);
                    w = xParent->left;
                    pointer_operations++;
                }
                w->color = xParent->color;
                xParent->color = black;
                w->left->color = black;
                rightRotate(xParent, pointer_operations);
                x = root;
                pointer_operations++;
            }
        }
    }
    pointer_operations++;
    if (x != nullptr)
        x->color = black;
}

void RBTree::deleteNode(int value, double &comparisons, double &pointer_operations)
{
    deleteNode(value, root, comparisons, pointer_operations);
}

void RBTree::deleteNode(int value, Node *&root, double &comparisons, double &pointer_operations)
{
    if (root == nullptr)
    {
        pointer_operations++;
        return;
    }
    if (value < root->value)
    {
        comparisons++;
        deleteNode(value, root->left, comparisons, pointer_operations);
    }
    else if (value > root->value)
    {
        comparisons++;
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
        }
        else if (root->right == nullptr)
        {
            pointer_operations += 3;
            Node *temp = root->left;
            temp->parent = root->parent;
            delete root;
            root = temp;
        }
        else
        {
            pointer_operations++;
            Node *successor = root->right;
            while (successor->left != nullptr)
            {
                pointer_operations += 2;
                successor = successor->left;
            }
            root->value = successor->value;
            deleteNode(successor->value, root->right, comparisons, pointer_operations);
        }
        pointer_operations++;
        if (root != nullptr)
            fixDelete(root, root->parent, pointer_operations);
    }
}
