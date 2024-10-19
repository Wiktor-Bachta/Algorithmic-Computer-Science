#include "BSTree.hpp"
#include <iostream>
#include "demonstration.hpp"
#include "generator.hpp"
#include <thread>
#include <chrono>

int main()
{
    BSTree tree;
    int n = 50;
    std::vector<int> in_sequence = generator::get_increasing_sequence(n);
    std::vector<int> out_sequence = generator::get_random_sequence(n);
    double comparisons = 0;
    double pointer_operations = 0;

    for (int i = 0; i < n; i++)
    {
        int key = in_sequence.at(i);
        std::cout << "insert " << key << std::endl;
        tree.insertNode(key, comparisons, pointer_operations);
        tree.printTree();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    for (int i = 0; i < n; i++)
    {
        int key = out_sequence.at(i);
        std::cout << "delete " << key << std::endl;
        tree.deleteNode(key, comparisons, pointer_operations);
        tree.printTree();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    tree.deleteTree();

    in_sequence = generator::get_random_sequence(n);
    for (int i = 0; i < n; i++)
    {
        int key = in_sequence.at(i);
        std::cout << "insert " << key << std::endl;
        tree.insertNode(key, comparisons, pointer_operations);
        tree.printTree();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    for (int i = 0; i < n; i++)
    {
        int key = out_sequence.at(i);
        std::cout << "delete " << key << std::endl;
        tree.deleteNode(key, comparisons, pointer_operations);
        tree.printTree();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    tree.deleteTree();
    return 0;
}