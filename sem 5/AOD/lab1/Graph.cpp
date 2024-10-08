#include "Graph.hpp"

Graph::Graph(std::string filepath)
{
    // Create a text string, which is used to output the text file
    std::string current_line;

    // Read from the text file
    std::ifstream source_file(filepath);

    // Use a while loop together with the getline() function to read the file line by line
    std::getline(source_file, current_line);
    if (current_line == "D")
    {
        is_directed_ = true;
    }
    else
    {
        is_directed_ = false;
    }

    std::getline(source_file, current_line);
    vertex_num_ = std::stoi(current_line);

    std::getline(source_file, current_line);
    edges_num_ = std::stoi(current_line);

    adjacency_matrix_ = std::vector<std::vector<bool>>(vertex_num_, std::vector<bool>(vertex_num_, false));

    for (int i = 0; i < 2 * edges_num_; i += 2)
    {
        std::getline(source_file, current_line, ' ');
        int vertex1 = std::stoi(current_line) - 1;

        std::getline(source_file, current_line);
        int vertex2 = std::stoi(current_line) - 1;

        adjacency_matrix_[vertex1][vertex2] = true;

        if (!is_directed_)
        {
            adjacency_matrix_[vertex2][vertex1] = true;
        }
    }

    // Close the file
    source_file.close();
}

int Graph::get_vertex_num()
{
    return vertex_num_;
}

int Graph::get_edges_num()
{
    return edges_num_;
}

std::vector<std::vector<bool>> Graph::get_adjacency_matrix()
{
    return adjacency_matrix_;
}

std::vector<int> Graph::get_neighbours(int vertex)
{
    std::vector<int> neighbours = std::vector<int>();
    for (int other_vertex = vertex_num_ - 1; other_vertex >= 0; other_vertex--)
    {
        if (adjacency_matrix_[vertex][other_vertex])
        {
            neighbours.push_back(other_vertex);
        }
    }
    return neighbours;
}