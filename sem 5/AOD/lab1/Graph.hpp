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

struct Edge
{
    int vertex1;
    int vertex2;
    Edge(int vertex1, int vertex2) : vertex1(vertex1), vertex2(vertex2) {}
};

class Graph
{
public:
    Graph(std::string filepath);
    int get_vertex_num();
    int get_edges_num();
    std::vector<std::vector<bool>> get_adjacency_matrix();
    std::vector<int> get_neighbours(int vertex);
private:
    bool is_directed_;
    int vertex_num_;
    int edges_num_;
    std::vector<std::vector<bool>> adjacency_matrix_;
    
};

#endif