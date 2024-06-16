#include "Signaling.hpp"

std::vector<Solution> Signaling::get_solution(int root_vertex, Graph graph)
{
    return Signaling::get_solution(root_vertex, Signaling::get_children_list(root_vertex, graph));
}

std::vector<std::vector<int>> Signaling::get_children_list(int root_vertex, Graph graph)
{
    int size = graph.get_size();
    std::vector<std::vector<int>> children_list(size, std::vector<int>());

    std::vector<bool> done(size, false);
    std::queue<int> queue;

    queue.push(root_vertex);

    while (!queue.empty())
    {
        int current = queue.front();
        queue.pop();
        for (int i = 0; i < size; i++)
        {
            if (graph.adjacency_matrix[current][i] != 0 && !done[i])
            {
                children_list[current].push_back(i);
                queue.push(i);
            }
        }
        done[current] = true;
    }
    return children_list;
}

std::vector<Solution> Signaling::get_solution(int root_vertex, std::vector<std::vector<int>> children_list)
{
    std::vector<Solution> solutions(children_list.size(), Solution(0));
    Signaling::solve(root_vertex, children_list, solutions);
    return solutions;
}

void Signaling::solve(int vertex, std::vector<std::vector<int>> children_list, std::vector<Solution> &solutions)
{
    std::vector<int> children = children_list[vertex];
    if (children.empty())
    {
        return;
    }

    for (auto &child : children)
    {
        solve(child, children_list, solutions);
    }

    std::sort(children.begin(), children.end(), [&](const int &a, const int &b)
              { return solutions[a].time > solutions[b].time; });

    solutions[vertex].ordered_children = children;
    solutions[vertex].time = solutions[children[0]].time + 1;

    for (int i = 1; i < (int)children.size(); i++)
    {
        if (solutions[vertex].time < solutions[children[i]].time + i + 1)
        {
            solutions[vertex].time = solutions[children[i]].time + i + 1;
        }
    }
}
