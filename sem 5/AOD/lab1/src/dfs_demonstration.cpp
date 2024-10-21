#include "Graph.hpp"
#include "searches.hpp"
#include <string.h>

int main(int argc, char* argv[]) {

    bool print_tree_flag = false;
    if (argc > 2 && strcmp(argv[2], "-p") == 0) {
        print_tree_flag = true;
    }

    std::string filename = std::string(argv[1]);

    Graph g = Graph(filename);
    dfs(g, true, print_tree_flag);

    return 0;
}