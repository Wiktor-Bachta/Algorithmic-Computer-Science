#include "connected_components_tarjan.hpp"

std::vector<std::vector<int>> get_connected_components(Graph g)
{
    int vertex_num = g.get_vertex_num();
    std::vector<std::vector<int>> edges = g.get_edges_when_loaded();
    int current_index = 0;
    std::stack<int> stack = std::stack<int>();
    std::vector<int> index = std::vector<int>(vertex_num, -1);
    std::vector<int> lowlink = std::vector<int>(vertex_num, -1);
    std::vector<bool> on_stack = std::vector<bool>(vertex_num, false);
    std::vector<std::vector<int>> connected_components = std::vector<std::vector<int>>();

    for (int vertex = 0; vertex < vertex_num; vertex++)
    {
        if (index[vertex] == -1)
        {
            strongconnect(vertex, current_index, stack, index, lowlink, on_stack, connected_components, edges);
        }
    }

    return connected_components;
}

void strongconnect(int vertex, int &current_index, std::stack<int> &stack, std::vector<int> &index, std::vector<int> &lowlink,
                   std::vector<bool> &on_stack, std::vector<std::vector<int>> &connected_components, std::vector<std::vector<int>> &edges)
{
    //std::cout << vertex + 1 << "\n";
    index[vertex] = current_index;
    lowlink[vertex] = current_index;
    current_index++;
    stack.push(vertex);
    on_stack[vertex] = true;

    for (const auto &succesor : edges[vertex])
    {
        if (index[succesor] == -1)
        {
            strongconnect(succesor, current_index, stack, index, lowlink, on_stack, connected_components, edges);
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

/*
function strongconnect(v)
        // Set the depth index for v to the smallest unused index
        v.index := index
        v.lowlink := index
        index := index + 1
        S.push(v)
        v.onStack := true

        // Consider successors of v
        for each (v, w) in E do
            if w.index is undefined then
                // Successor w has not yet been visited; recurse on it
                strongconnect(w)
                v.lowlink := min(v.lowlink, w.lowlink)
            else if w.onStack then
                // Successor w is in stack S and hence in the current SCC
                // If w is not on stack, then (v, w) is an edge pointing to an SCC already found and must be ignored
                // See below regarding the next line
                v.lowlink := min(v.lowlink, w.index)

        // If v is a root node, pop the stack and generate an SCC
        if v.lowlink = v.index then
            start a new strongly connected component
            repeat
                w := S.pop()
                w.onStack := false
                add w to current strongly connected component
            while w ≠ v
            output the current strongly connected component
*/