#ifndef SEARCHES_HPP
#define SEARCHES_HPP

#include "Graph.hpp"
#include <stack>
#include <queue>

void dfs(Graph &graph, bool print_flag, bool save_tree_flag);

void bfs(Graph &graph, bool print_flag, bool save_tree_flag);

#endif