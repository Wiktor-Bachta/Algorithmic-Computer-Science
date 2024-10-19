#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <vector>
#include <algorithm>
#include <random>

class generator
{
public:
    static std::vector<int> get_random_sequence(int n);
    static std::vector<int> get_increasing_sequence(int n);
    static std::vector<int> get_decreasing_sequence(int n);
};

#endif