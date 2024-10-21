#include "topological_sort_kahn.hpp"

bool is_acyclic(Graph &graph, bool print_flag)
{
    std::vector<int> sorted_verticies = std::vector<int>();
    std::stack<int> vertices_without_incoming_edges = std::stack<int>();
    std::vector<int> incoming_edge_count = std::vector<int>(graph.vertex_num, 0);
    int current_vertex;

    for (int vertex = 0; vertex < graph.vertex_num; vertex++)
    {
        for (const auto &successor : graph.adjacency_list[vertex])
        {
            incoming_edge_count[successor]++;
        }
    }

    for (int vertex = 0; vertex < graph.vertex_num; vertex++)
    {
        if (incoming_edge_count[vertex] == 0)
        {
            vertices_without_incoming_edges.push(vertex);
        }
    }

    while (!vertices_without_incoming_edges.empty())
    {
        current_vertex = vertices_without_incoming_edges.top();
        vertices_without_incoming_edges.pop();
        sorted_verticies.push_back(current_vertex);

        for (const auto &successor : graph.adjacency_list[current_vertex])
        {
            incoming_edge_count[successor]--;
            if (incoming_edge_count[successor] == 0)
            {
                vertices_without_incoming_edges.push(successor);
            }
        }
    }

    if (graph_has_edges(incoming_edge_count))
    {
        return false;
    }

    if (print_flag)
    {
        for (const auto vertex : sorted_verticies)
        {
            std::cout << vertex + 1 << "-> ";
        }
    }

    return true;
}

bool graph_has_edges(std::vector<int> &incoming_edge_count)
{
    for (const auto &i : incoming_edge_count)
    {
        if (i != 0)
        {
            return true;
        }
    }
    return false;
}
