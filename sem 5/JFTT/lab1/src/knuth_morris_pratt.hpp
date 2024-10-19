#ifndef KNUTH_MORRISS_PRATT_HPP
#define KNUTH_MORRISS_PRATT_HPP

#include <vector>
#include <string>

std::vector<int> compute_prefix_function (std::string &pattern);

std::vector<int> search(std::string &pattern, std::string &text);

#endif