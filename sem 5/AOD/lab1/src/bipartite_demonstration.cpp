#include "Graph.hpp"
#include "bipartite_dfs.hpp"

int main(int, char *argv[])
{
    std::string filename = std::string(argv[1]);

    Graph g = Graph(filename);

    bool print_flag = false;
    if (g.vertex_num <= 200)
    {
        print_flag = true;
    }

    bool bipartite = is_bapartite(g, print_flag);

    if (bipartite)
    {
        std::cout << "Graf jest dwudzielny\n";
    }
    else
    {
        std::cout << "Graf nie jest dwudzielny\n";
    }

    return 0;
}