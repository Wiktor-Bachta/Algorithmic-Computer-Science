#ifndef CONNECTED_COMPONENTS_TARJAN_HPP
#define CONNECTED_COMPONENTS_TARJAN_HPP

#include "Graph.hpp"
#include <stack>

std::vector<std::vector<int>> get_connected_components(Graph &graph);

void strongconnect(int vertex, int &current_index, std::stack<int> &stack, std::vector<int> &index, std::vector<int> &lowlink,
                   std::vector<bool> &on_stack, std::vector<std::vector<int>> &connected_components, std::vector<std::vector<int>> &adjacency_list);

#endif