#include "bipartite_dfs.hpp"

bool is_bapartite(Graph g, bool print_flag)
{
    int vertex_num = g.get_vertex_num();
    std::vector<std::vector<int>> edges = g.get_edges_when_loaded();
    std::vector<bool> visited = std::vector<bool>(vertex_num, false);
    std::vector<bool> colored = std::vector<bool>(vertex_num, false);
    std::stack<int> stack;
    stack.push(0);
    int current_vertex;
    int num_unvisited = vertex_num;

    // just treat graph as not directed anyway
    if (g.is_directed())
    {
        for (int vertex = 0; vertex < vertex_num; vertex++)
        {
            for (const auto &neighbour : edges[vertex])
            {
                if (std::find(edges[neighbour].begin(), edges[neighbour].end(), vertex) == edges[neighbour].end())
                {
                    edges[neighbour].push_back(vertex);
                }
            }
        }
    }

    while (!stack.empty() || num_unvisited != 0) // for non connected graphs
    {
        if (stack.empty())
        {
            stack.push(get_first_unvisited_vertex(visited));
        }

        current_vertex = stack.top();
        stack.pop();

        if (!visited[current_vertex])
        {
            num_unvisited--;
            visited[current_vertex] = true;
            for (const auto &neighbour : edges[current_vertex])
            {
                if (!visited[neighbour])
                {
                    colored[neighbour] = !colored[current_vertex];
                    stack.push(neighbour);
                }
                else if (colored[neighbour] == colored[current_vertex])
                {
                    //std::cout << current_vertex + 1 << " " << neighbour + 1 << "\n";
                    return false;
                }
            }
        }
    }

    if (print_flag)
    {
        std::cout << "Wierzchołki niebieskie:\n";
        for (int vertex = 0; vertex < vertex_num; vertex++)
        {
            if (colored[vertex])
            {
                std::cout << vertex + 1 << "\n";
            }
        }
        std::cout << "Wierzchołki czerwone:\n";
        for (int vertex = 0; vertex < vertex_num; vertex++)
        {
            if (!colored[vertex])
            {
                std::cout << vertex + 1 << "\n";
            }
        }
    }

    return true;
}

int get_first_unvisited_vertex(std::vector<bool> &visited)
{
    int vertex_num = visited.size();
    for (int vertex = 0; vertex < vertex_num; vertex++)
    {
        if (!visited[vertex])
        {
            return vertex;
        }
    }
    return -1;
}