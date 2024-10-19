#include "finite_automata.hpp"

std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

std::vector<std::map<char, int>> compute_transition_function(std::string &pattern)
{
    int pattern_length = pattern.length();
    int longest_suffix_state = 0;
    std::vector<std::map<char, int>> transition_function = std::vector<std::map<char, int>>(pattern_length + 1, std::map<char, int>());

    for (const auto &character : alphabet)
    {
        transition_function[0][character] = 0;
    }
    transition_function[0][pattern[0]] = 1;

    for (int state = 1; state <= pattern_length; state++)
    {
        for (const auto &character : alphabet)
        {
            transition_function[state][character] = transition_function[longest_suffix_state][character];
        }

        if (state != pattern_length)
        {
            transition_function[state][pattern[state]] = state + 1;

            longest_suffix_state = transition_function[longest_suffix_state][pattern[state]];
        }
    }

    return transition_function;
}

std::vector<int> search(std::string &pattern, std::string &text)
{
    int pattern_length = pattern.length();
    int text_length = text.length();
    std::vector<int> pattern_indexes = std::vector<int>();
    int current_state = 0;

    std::vector<std::map<char, int>> transition_function = compute_transition_function(pattern);

    for (int i = 0; i < text_length; i++)
    {
        current_state = transition_function[current_state][text[i]];
        if (current_state == pattern_length)
        {
            pattern_indexes.push_back(i - pattern_length + 1);
        }
    }

    return pattern_indexes;
}
