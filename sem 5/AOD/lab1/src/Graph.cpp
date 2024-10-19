#include "Graph.hpp"

Graph::Graph(std::string filepath)
{
    std::string current_line;
    std::ifstream source_file(filepath);

    std::getline(source_file, current_line);
    if (current_line[0] == 'D')
    {
        is_directed = true;
    }
    else
    {
        is_directed = false;
    }

    std::getline(source_file, current_line);
    vertex_num = std::stoi(current_line);

    std::getline(source_file, current_line);
    edges_num = std::stoi(current_line);
    adjacency_list = std::vector<std::vector<int>>(vertex_num, std::vector<int>());

    for (int i = 0; i < 2 * edges_num; i += 2)
    {
        std::getline(source_file, current_line, ' ');
        int vertex1 = std::stoi(current_line) - 1;

        std::getline(source_file, current_line);
        int vertex2 = std::stoi(current_line) - 1;

        adjacency_list[vertex1].push_back(vertex2);

        if (!is_directed)
        {
            adjacency_list[vertex2].push_back(vertex1);
        }
    }

    source_file.close();
}