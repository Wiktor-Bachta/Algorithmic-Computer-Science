#ifndef FINITE_AUTOMATA_HPP
#define FINITE_AUTOMATA_HPP

#include <vector>
#include <map>
#include <string>

std::vector<std::map<char, int>> compute_transition_function(std::string &pattern);

std::vector<int> search(std::string &pattern, std::string &text);

#endif