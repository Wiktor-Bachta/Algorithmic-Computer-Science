#include "SplayTree.hpp"
#include "generator.hpp"
#include <iostream>
#include <fstream>
#include <vector>

int NUM_EXPERIMENTS = 1;
int MIN_N = 10000;
int MAX_N = 100000;
int STEP = 10000;

void experiment(std::vector<int> in, std::vector<int> out, std::ofstream &file, int n);

int main(void)
{
    std::ofstream file_random_random;
    std::ofstream file_increasing_random;
    file_random_random.open("./data/SplayTree/random_random.txt");
    file_increasing_random.open("./data/SplayTree/increasing_random.txt");
    file_random_random << "n,cmp,ptr,h,mcmp,mptr,mh\n";
    file_increasing_random << "n,cmp,ptr,h,mcmp,mptr,mh\n";
    for (int n = MIN_N; n <= MAX_N; n += STEP)
    {
        for (int i = 0; i < NUM_EXPERIMENTS; i++)
        {
            std::vector<int> in_sequence_increasing = generator::get_increasing_sequence(n);
            std::vector<int> in_sequence_radom = generator::get_random_sequence(n);
            std::vector<int> out_sequence = generator::get_random_sequence(n);
            experiment(in_sequence_increasing, out_sequence, file_increasing_random, n);
            experiment(in_sequence_radom, out_sequence, file_random_random, n);
        }
        std::cout << "n = " << n << " done\n";
    }
    file_random_random.close();
    file_increasing_random.close();
    return 0;
}

void experiment(std::vector<int> in_sequence, std::vector<int> out_sequence, std::ofstream &file, int n)
{
    double comparisons = 0;
    double pointer_operations = 0;
    double heights = 0;
    double max_comparisons = 0;
    double max_pointer_operations = 0;
    int max_heights = 0;
    SplayTree tree;
    for (int i = 0; i < n; i++)
    {
        int tmp_comparisons = comparisons;
        int tmp_pointer_operations = pointer_operations;
        int key = in_sequence.at(i);
        tree.insertNode(key, comparisons, pointer_operations);
        int height = tree.height();
        heights += height;
        max_comparisons = std::max(max_comparisons, comparisons - tmp_comparisons);
        max_pointer_operations = std::max(max_pointer_operations, pointer_operations - tmp_pointer_operations);
        max_heights = std::max(max_heights, height);
    }

    for (int i = 0; i < n; i++)
    {
        int tmp_comparisons = comparisons;
        int tmp_pointer_operations = pointer_operations;
        int key = out_sequence.at(i);
        tree.deleteNode(key, comparisons, pointer_operations);
        int height = tree.height();
        heights += height;
        max_comparisons = std::max(max_comparisons, comparisons - tmp_comparisons);
        max_pointer_operations = std::max(max_pointer_operations, pointer_operations - tmp_pointer_operations);
    }
    tree.deleteTree();
    file << n << "," << (float)(comparisons / (2 * n)) << "," << (float)(pointer_operations / (2 * n)) << "," << (float)(heights / (2 * n)) << "," << max_comparisons << "," << max_pointer_operations << "," << max_heights << "\n";
}