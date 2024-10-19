#include "generator.hpp"

std::vector<int> generator::get_random_sequence(int n)
{

    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(0, 2 * n - 1);
    std::vector<int> sequence;

    for (int i = 0; i < n; i++)
    {
        sequence.push_back(distr(generator));
    }
    return sequence;
}

std::vector<int> generator::get_increasing_sequence(int n)
{
    std::vector<int> sequence = get_random_sequence(n);
    std::sort(sequence.begin(), sequence.end());
    return sequence;
}

std::vector<int> generator::get_decreasing_sequence(int n)
{
    std::vector<int> sequence = get_random_sequence(n);
    std::sort(sequence.begin(), sequence.end());
    std::reverse(sequence.begin(), sequence.end());
    return sequence;
}
