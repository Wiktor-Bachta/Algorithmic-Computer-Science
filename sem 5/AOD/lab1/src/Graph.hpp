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
    Graph(std::string filepath);
    bool is_directed();
    int get_vertex_num();
    int get_edges_num();
    std::vector<std::vector<int>> get_edges_when_loaded();
    std::vector<std::vector<bool>> get_adjacency_matrix();
    std::vector<int> get_neighbours(int vertex);
    void set_edge(int vertex_from, int vertex_to, bool edge_exits);
    std::vector<std::vector<int>> get_edges();

private:
    int MAX_SIZE_FOR_ADJACENCY_MATRIX;
    bool is_directed_;
    int vertex_num_;
    int edges_num_;
    std::vector<std::vector<int>> edges_when_loaded_;
    std::vector<std::vector<bool>> adjacency_matrix_;
};

#endif