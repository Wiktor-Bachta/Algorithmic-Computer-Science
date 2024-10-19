#include "Graph.hpp"
#include "topological_sort_kahn.hpp"
#include <string.h>
#include <iostream>

int main(int, char *argv[])
{

    std::string filename = std::string(argv[1]);

    Graph g = Graph(filename);

    if (!g.is_directed)
    {
        std::cout << "Graf nie jest skierowany\n";
        return 1;
    }

    bool print_flag = false;
    if (g.vertex_num <= 200)
    {
        print_flag = true;
    }

    bool acyclic = is_acyclic(g, print_flag);

    if (!acyclic)
    {
        std::cout << "Graf zawiera skierowany cykl\n";
    }
    else
    {
        std::cout << "Graf nie zawiera skierowanego cyklu\n";
    }

    return 0;
}