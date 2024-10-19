#include "knuth_morris_pratt.hpp"
#include <iostream>

std::vector<int> compute_prefix_function(std::string &pattern)
{
    int pattern_length = pattern.length();
    std::vector<int> prefix_function = std::vector<int>(pattern_length);
    prefix_function[0] = 0;
    int longest_prefix = 0;

    for (int i = 1; i < pattern_length; i++)
    {
        while (longest_prefix > 0 && pattern[longest_prefix] != pattern[i])
        {
            longest_prefix = prefix_function[longest_prefix - 1];
        }
        if (pattern[longest_prefix] == pattern[i])
        {
            longest_prefix++;
        }
        prefix_function[i] = longest_prefix;
    }

    return prefix_function;
}

std::vector<int> search(std::string &pattern, std::string &text)
{
    std::vector<int> pattern_indexes = std::vector<int>();
    std::vector<int> prefix_function = compute_prefix_function(pattern);
    int characters_matched = 0;
    int pattern_length = pattern.length();
    int text_length = text.length();

    for (int i = 0; i < text_length; i++)
    {
        while (characters_matched > 0 && pattern[characters_matched] != text[i])
        {
            characters_matched = prefix_function[characters_matched - 1];
        }
        if (pattern[characters_matched] == text[i])
        {
            characters_matched++;
        }
        if (characters_matched == pattern_length)
        {
            pattern_indexes.push_back(i - pattern_length + 1);
            characters_matched = prefix_function[characters_matched - 1];
        }
    }

    return pattern_indexes;
}