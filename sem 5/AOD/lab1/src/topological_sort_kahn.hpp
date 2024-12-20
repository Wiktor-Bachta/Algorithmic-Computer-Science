#ifndef TOPOLOGICAL_SORT_KAHN_HPP
#define TOPOLOGICAL_SORT_KAHN_HPP

#include "Graph.hpp"
#include <stack>

bool is_acyclic(Graph &graph, bool print_flag);

bool graph_has_edges(std::vector<int> &incoming_edge_count);

#endif