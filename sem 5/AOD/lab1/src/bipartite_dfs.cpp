#include "bipartite_dfs.hpp"

bool is_bapartite(Graph &graph, bool print_flag)
{
    std::vector<std::vector<int>> adjacency_list_undirected = graph.adjacency_list;
    std::vector<bool> visited = std::vector<bool>(graph.vertex_num, false);
    std::vector<bool> colored = std::vector<bool>(graph.vertex_num, false);
    std::stack<int> stack;
    stack.push(0);
    int current_vertex;
    int num_unvisited = graph.vertex_num;

    // just treat graph as not directed anyway
    if (graph.is_directed)
    {
        for (int vertex = 0; vertex < graph.vertex_num; vertex++)
        {
            for (const auto &successor : graph.adjacency_list[vertex])
            {
                if (std::find(graph.adjacency_list[successor].begin(), graph.adjacency_list[successor].end(), vertex) == graph.adjacency_list[successor].end())
                {
                    adjacency_list_undirected[successor].push_back(vertex);
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
            visited[current_vertex] = true;
            num_unvisited--;
            for (const auto &successor : adjacency_list_undirected[current_vertex])
            {
                if (!visited[successor])
                {
                    colored[successor] = !colored[current_vertex];
                    stack.push(successor);
                }
                else if (colored[successor] == colored[current_vertex])
                {
                    return false;
                }
            }
        }
    }

    if (print_flag)
    {
        std::cout << "Wierzchołki niebieskie:\n";
        for (int vertex = 0; vertex < graph.vertex_num; vertex++)
        {
            if (colored[vertex])
            {
                std::cout << vertex + 1 << ", ";
            }
        }
        std::cout << "\nWierzchołki czerwone:\n";
        for (int vertex = 0; vertex < graph.vertex_num; vertex++)
        {
            if (!colored[vertex])
            {
                std::cout << vertex + 1 << ", ";
            }
        }
        std::cout << "\n";
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