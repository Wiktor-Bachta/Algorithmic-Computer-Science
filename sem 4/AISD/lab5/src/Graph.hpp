#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
#include <limits>
#include <iomanip>

typedef struct Edge
{
    int vertex1;
    int vertex2;
    double weight;
    Edge(int vertex1, int vertex2, double weight) : vertex1(vertex1), vertex2(vertex2), weight(weight) {}
} Edge;

class Graph
{
public:
    std::vector<std::vector<double>> adjacency_matrix;

    void generate_random_full_graph();
    void modify_edge(int vertex1, int vertex2, double weight);
    int get_size();
    Graph get_MST_Kruskal();
    Graph get_MST_Prim();
    Graph(int size);
    void print_adjacency_matrix();

private:
    int vertex_num_;
    int edges_num_;

    double get_random_value();
    int find(int vertex, std::vector<int> previous);
    void set_union(int vertex1, int vertex2, std::vector<int> &previous, std::vector<int> &ranks);
    int min_key(std::vector<double> costs, std::vector<bool> visited);
    std::vector<Edge> get_sorted_edges();
};

#endif