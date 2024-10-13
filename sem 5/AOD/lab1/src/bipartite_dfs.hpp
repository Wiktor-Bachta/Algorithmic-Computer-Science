#ifndef BIPARTITE_DFS_HPP
#define BIPARTITE_DFS_HPP

#include "Graph.hpp"
#include <iostream>
#include <stack>

bool is_bapartite(Graph g, bool print_flag);

int get_first_unvisited_vertex(std::vector<bool> &visited);

#endif