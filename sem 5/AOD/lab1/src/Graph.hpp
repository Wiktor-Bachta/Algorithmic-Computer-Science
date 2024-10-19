#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <string>
#include <fstream>

class Graph
{
public:
    bool is_directed;
    int vertex_num;
    int edges_num;
    std::vector<std::vector<int>> adjacency_list;

    Graph(std::string filepath);
};

#endif