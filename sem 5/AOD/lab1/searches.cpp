#include "Graph.hpp"
#include "searches.hpp"
#include <stack>
#include <queue>

void dfs(Graph g, bool print_flag, bool save_tree_flag)
{
    if (save_tree_flag)
    {
        std::ofstream out_file("/home/wiktor/Desktop/AOD/lab1/tree.txt");
        out_file << g.get_vertex_num() << "\n";
        out_file.close();
    }

    std::vector<bool> visited = std::vector<bool>(g.get_vertex_num(), false);
    std::stack<std::pair<int, int>> stack;
    stack.push(std::make_pair(0, 0));
    int parent, current_vertex;

    while (!stack.empty())
    {
        parent = stack.top().first;
        current_vertex = stack.top().second;
        stack.pop();

        if (!visited[current_vertex])
        {
            if (save_tree_flag)
            {
                std::ofstream out_file;
                out_file.open("/home/wiktor/Desktop/AOD/lab1/tree.txt", std::ios_base::app);
                out_file << parent + 1 << " " << current_vertex + 1 << "\n";
                out_file.close();
            }

            if (print_flag)
            {
                std::cout << current_vertex + 1 << "\n";
            }


            visited[current_vertex] = true;
            for (const auto &neighbour : g.get_neighbours(current_vertex))
            {
                if (!visited[neighbour])
                {
                    stack.push(std::make_pair(current_vertex, neighbour));
                }
            }
        }
    }
}

void bfs(Graph g, bool print_flag, bool save_tree_flag)
{
    if (save_tree_flag)
    {
        std::ofstream out_file("/home/wiktor/Desktop/AOD/lab1/tree.txt");
        out_file << g.get_vertex_num() << "\n";
        out_file.close();
    }

    std::vector<bool> visited = std::vector<bool>(g.get_vertex_num(), false);
    std::queue<std::pair<int, int>> queue;
    queue.push(std::make_pair(0, 0));
    visited[0] = true;
    int parent, current_vertex;

    while (!queue.empty())
    {
        parent = queue.front().first;
        current_vertex = queue.front().second;
        queue.pop();

            if (save_tree_flag)
            {
                std::ofstream out_file;
                out_file.open("/home/wiktor/Desktop/AOD/lab1/tree.txt", std::ios_base::app);
                out_file << parent + 1 << " " << current_vertex + 1 << "\n";
                out_file.close();
            }

            if (print_flag)
            {
                std::cout << current_vertex + 1 << "\n";
            }

            for (const auto &neighbour : g.get_neighbours(current_vertex))
            {
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    queue.push(std::make_pair(current_vertex, neighbour));
                }
            }
    }
}