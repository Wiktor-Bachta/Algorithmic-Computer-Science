#include "Graph.hpp"
#include "connected_components_tarjan.hpp"
#include <string.h>
#include <iostream>

int main(int, char *argv[])
{

    std::string filename = std::string(argv[1]);

    Graph g = Graph(filename);

    std::vector<std::vector<int>> connected_components = get_connected_components(g);
    int components_num = connected_components.size();

    std::cout << "Liczba silnie spójnych składowych " << components_num << "\n";

    for (int i = 0; i < components_num; i++)
    {
        std::cout << "Rozmiar komponentu " << i + 1 << ": " << connected_components[i].size() << "\n";
        if (g.get_vertex_num() <= 200)
        {
            for (const auto &vertex : connected_components[i])
            {
                std::cout << vertex + 1 << "\n";
            }
        }
    }

    return 0;
}