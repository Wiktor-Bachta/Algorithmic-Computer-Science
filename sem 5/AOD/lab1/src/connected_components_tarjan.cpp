#include "connected_components_tarjan.hpp"

std::vector<std::vector<int>> get_connected_components(Graph &graph)
{
    int current_index = 0;
    std::stack<int> stack = std::stack<int>();
    std::vector<int> index = std::vector<int>(graph.vertex_num, -1);
    std::vector<int> lowlink = std::vector<int>(graph.vertex_num, -1);
    std::vector<bool> on_stack = std::vector<bool>(graph.vertex_num, false);
    std::vector<std::vector<int>> connected_components = std::vector<std::vector<int>>();

    for (int vertex = 0; vertex < graph.vertex_num; vertex++)
    {
        if (index[vertex] == -1)
        {
            strongconnect(vertex, current_index, stack, index, lowlink, on_stack, connected_components, graph.adjacency_list);
        }
    }

    return connected_components;
}

void strongconnect(int vertex, int &current_index, std::stack<int> &stack, std::vector<int> &index, std::vector<int> &lowlink,
                   std::vector<bool> &on_stack, std::vector<std::vector<int>> &connected_components, std::vector<std::vector<int>> &adjacency_list)
{
    index[vertex] = current_index;
    lowlink[vertex] = current_index;
    current_index++;
    stack.push(vertex);
    on_stack[vertex] = true;

    for (const auto &succesor : adjacency_list[vertex])
    {
        if (index[succesor] == -1)
        {
            strongconnect(succesor, current_index, stack, index, lowlink, on_stack, connected_components, adjacency_list);
            lowlink[vertex] = std::min(lowlink[vertex], lowlink[succesor]);
        }
        else if (on_stack[succesor])
        {
            lowlink[vertex] = std::min(lowlink[vertex], lowlink[succesor]);
        }
    }

    if (lowlink[vertex] == index[vertex])
    {
        int vertex_in_component;
        std::vector<int> new_component = std::vector<int>();
        do
        {
            vertex_in_component = stack.top();
            stack.pop();
            on_stack[vertex_in_component] = false;
            new_component.push_back(vertex_in_component);
        } while (vertex_in_component != vertex);

        connected_components.push_back(new_component);
    }
}
