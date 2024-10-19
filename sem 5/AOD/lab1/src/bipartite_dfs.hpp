#ifndef BIPARTITE_DFS_HPP
#define BIPARTITE_DFS_HPP

#include "Graph.hpp"
#include <stack>
#include <algorithm>

bool is_bapartite(Graph &graph, bool print_flag);

int get_first_unvisited_vertex(std::vector<bool> &visited);

#endif