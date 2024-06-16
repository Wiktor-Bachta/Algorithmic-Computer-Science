#include "Graph.hpp"
#include "Signaling.hpp"
#include <iostream>

int SIZE = 20;

int main(void)
{
    Graph graph(SIZE);
    graph.generate_random_full_graph();
    Graph MST = graph.get_MST_Prim();

    std::cout << "Full graph:\n";
    graph.print_adjacency_matrix();

    std::cout << "\nMST graph:\n";
    MST.print_adjacency_matrix();

    std::cout << "\nSolution for signaling starting at vertex 0\n";
    std::vector<Solution> solutions = Signaling::get_solution(0, MST);
    for (int i = 0; i < (int)solutions.size(); i++)
    {
        std::cout << i << ": ";
        for (int j = 0; j < (int)solutions[i].ordered_children.size(); j++)
        {
            std::cout << solutions[i].ordered_children[j] << ", ";
        }
        std::cout << "(" << solutions[i].time << ")\n";
    }
}