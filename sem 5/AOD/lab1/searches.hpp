#ifndef SEARCHES_HPP
#define SEARCHES_HPP

#include "Graph.hpp"
#include <iostream>
#include <fstream>
#include <utility>

void dfs(Graph g, bool print_flag, bool save_tree_flag);

void bfs(Graph g, bool print_flag, bool save_tree_flag);

#endif