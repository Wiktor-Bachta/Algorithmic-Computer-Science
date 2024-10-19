#include "demonstration.hpp"

void demonstration::in_increasing_out_random(int n) {
    BSTree tree;
    std::vector<int> in_sequence = generator::get_increasing_sequence(n);
    std::vector<int> out_sequence = generator::get_random_sequence(n);
    double comparisons = 0;
    double pointer_operations = 0;

    for (int i = 0; i < n; i++) {
        int key = in_sequence.at(i);
        std::cout << "insert " << key << std::endl;
        tree.insertNode(key, comparisons, pointer_operations);
        tree.printTree();
    }

    for (int i = 0; i < n; i++) {
        int key = out_sequence.at(i);
        std::cout << "delete " << key << std::endl;
        tree.deleteNode(key, comparisons, pointer_operations);
        tree.printTree();
    }
}

void demonstration::in_random_out_random(int n) {
    BSTree tree;
    std::vector<int> in_sequence = generator::get_random_sequence(n);
    std::vector<int> out_sequence = generator::get_random_sequence(n);
    double comparisons = 0;
    double pointer_operations = 0;

    for (int i = 0; i < n; i++) {
        int key = in_sequence.at(i);
        std::cout << "insert " << key << std::endl;
        tree.insertNode(key, comparisons, pointer_operations);
        tree.printTree();
    }

    for (int i = 0; i < n; i++) {
        int key = out_sequence.at(i);
        std::cout << "delete " << key << std::endl;
        tree.deleteNode(key, comparisons, pointer_operations);
        tree.printTree();
    }
}