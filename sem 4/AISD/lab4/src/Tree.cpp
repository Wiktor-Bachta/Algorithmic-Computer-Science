#include "Tree.hpp"

Tree::Tree() : root(nullptr) {}

Tree::~Tree()
{
    deleteTree(root);
}

void Tree::deleteTree()
{
    deleteTree(root);
    root = nullptr;
}

void Tree::deleteTree(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void Tree::printTree()
{
    int size = treeSize();
    char *left_trace;  // needs to be allocaded with size
    char *right_trace; // needs to be allocaded with size
    left_trace = (char *)malloc(size * sizeof(char));
    right_trace = (char *)malloc(size * sizeof(char));
    for (int i = 0; i <= size; i++)
    {
        left_trace[i] = ' ';
        left_trace[i] = ' ';
    }
    printTree(root, 0, '-', left_trace, right_trace);
    free(left_trace);
    free(right_trace);
}

void Tree::printTree(Node *root, int depth, char prefix, char *&left_trace, char *&right_trace)
{
    if (root == nullptr)
        return;
    if (root->left != nullptr)
    {
        printTree(root->left, depth + 1, '/', left_trace, right_trace);
    }
    if (prefix == '/')
        left_trace[depth - 1] = '|';
    if (prefix == '\\')
        right_trace[depth - 1] = ' ';
    if (depth == 0)
        printf("-");
    if (depth > 0)
        printf(" ");
    for (int i = 0; i < depth - 1; i++)
        if (left_trace[i] == '|' || right_trace[i] == '|')
        {
            printf("| ");
        }
        else
        {
            printf("  ");
        }
    if (depth > 0)
        printf("%c-", prefix);
    printf("[%d]\n", root->value);
    left_trace[depth] = ' ';
    if (root->right != nullptr)
    {
        right_trace[depth] = '|';
        printTree(root->right, depth + 1, '\\', left_trace, right_trace);
    }
}

int Tree::treeSize()
{
    return treeSize(root);
}

int Tree::treeSize(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + treeSize(root->left) + treeSize(root->right);
}

int Tree::height()
{
    return height(root);
}

int Tree::height(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + std::max(height(root->left), height(root->right));
}

Node* Tree::minimum(Node *node)
{
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}