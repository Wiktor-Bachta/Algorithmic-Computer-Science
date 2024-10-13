#include "topological_sort_kahn.hpp"

bool is_acyclic(Graph g, bool print_flag)
{
    int vertex_num = g.get_vertex_num();

    std::vector<int> sorted_verticies = std::vector<int>();
    std::stack<int> vertices_no_incoming_edges = std::stack<int>();
    int current_vertex;

    std::vector<int> incoming_edge_count = std::vector<int>(vertex_num, 0);
    std::vector<std::vector<int>> vertecies_to = g.get_edges_when_loaded();

    for (int vertex = 0; vertex < vertex_num; vertex++)
    {
        for (const auto &vertex_to : vertecies_to[vertex])
        {
            //std::cout << vertex << " " << vertex_to << "\n";
            incoming_edge_count[vertex_to]++;
        }
    }

    for (int vertex = 0; vertex < vertex_num; vertex++)
    {
        //std::cout << vertex << " ma wchodzących " << incoming_edge_count[vertex] << "\n";
        if (incoming_edge_count[vertex] == 0)
        {
            vertices_no_incoming_edges.push(vertex);
        }
    }

    while (!vertices_no_incoming_edges.empty())
    {
        current_vertex = vertices_no_incoming_edges.top();
        vertices_no_incoming_edges.pop();
        //std::cout << current_vertex + 1 << "\n";
        sorted_verticies.push_back(current_vertex);

        std::vector<int> neighbours = vertecies_to[current_vertex];
        vertecies_to[current_vertex].clear();
        for (const auto &neighbour : neighbours)
        {
            //std::cout << current_vertex << " " <<  neighbour << "\n";
            incoming_edge_count[neighbour]--;
            if (incoming_edge_count[neighbour] == 0)
            {
                vertices_no_incoming_edges.push(neighbour);
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
            std::cout << vertex + 1 << "\n";
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
