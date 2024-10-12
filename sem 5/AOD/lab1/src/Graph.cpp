#include "Graph.hpp"

Graph::Graph(std::string filepath)
{
    MAX_SIZE_FOR_ADJACENCY_MATRIX = 100;

    // Create a text string, which is used to output the text file
    std::string current_line;

    // Read from the text file
    std::ifstream source_file(filepath);

    // Use a while loop together with the getline() function to read the file line by line
    std::getline(source_file, current_line);
    if (current_line[0] == 'D')
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

    if (vertex_num_ <= MAX_SIZE_FOR_ADJACENCY_MATRIX)
    {
        adjacency_matrix_ = std::vector<std::vector<bool>>(vertex_num_, std::vector<bool>(vertex_num_, false));
    }
    edges_when_loaded_ = std::vector<std::vector<int>>(vertex_num_, std::vector<int>());

    for (int i = 0; i < 2 * edges_num_; i += 2)
    {
        //std::cout << i / 2 << "\n";
        std::getline(source_file, current_line, ' ');
        int vertex1 = std::stoi(current_line) - 1;

        std::getline(source_file, current_line);
        int vertex2 = std::stoi(current_line) - 1;

        if (vertex_num_ <= MAX_SIZE_FOR_ADJACENCY_MATRIX)
        {
            adjacency_matrix_[vertex1][vertex2] = true;
        }
        edges_when_loaded_[vertex1].push_back(vertex2);

        if (!is_directed_)
        {
            if (vertex_num_ <= MAX_SIZE_FOR_ADJACENCY_MATRIX)
            {
                adjacency_matrix_[vertex2][vertex1] = true;
            }
            edges_when_loaded_[vertex2].push_back(vertex1);
        }
    }

    // Close the file
    source_file.close();
    //std::cout << "stworzonko\n";
}

int Graph::get_vertex_num()
{
    return vertex_num_;
}

int Graph::get_edges_num()
{
    return edges_num_;
}

bool Graph::is_directed()
{
    return is_directed_;
}

std::vector<std::vector<int>> Graph::get_edges_when_loaded()
{
    return edges_when_loaded_;
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

void Graph::set_edge(int vertex_from, int vertex_to, bool edge_exits)
{
    bool currently_exists = adjacency_matrix_[vertex_from][vertex_to];
    adjacency_matrix_[vertex_from][vertex_to] = edge_exits;

    if (currently_exists != edge_exits)
    {
        if (currently_exists)
        {
            edges_num_--;
        }
        else
        {
            edges_num_++;
        }
    }
}

std::vector<std::vector<int>> Graph::get_edges()
{

    std::vector<std::vector<int>> result = std::vector<std::vector<int>>(vertex_num_, std::vector<int>());

    for (int vertex_from = 0; vertex_from < vertex_num_; vertex_from++)
    {
        for (int vertex_to = 0; vertex_to < vertex_num_; vertex_to++)
        {
            if (adjacency_matrix_[vertex_from][vertex_to])
            {
                result[vertex_from].push_back(vertex_to);
            }
        }
    }

    return result;
}