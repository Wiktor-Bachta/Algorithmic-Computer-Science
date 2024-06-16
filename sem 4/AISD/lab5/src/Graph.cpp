#include "Graph.hpp"

Graph::Graph(int size)
{
    vertex_num_ = size;
    edges_num_ = 0;
    adjacency_matrix = std::vector<std::vector<double>>(vertex_num_, std::vector<double>(vertex_num_, 0));
}

void Graph::generate_random_full_graph()
{
    edges_num_ = 0;
    for (int i = 0; i < vertex_num_; i++)
    {
        for (int j = i + 1; j < vertex_num_; j++)
        {
            double weight = get_random_value();
            if (weight != 0)
            {
                edges_num_++;
            }
            adjacency_matrix[i][j] = weight;
            adjacency_matrix[j][i] = weight;
        }
    }
}

void Graph::modify_edge(int vertex1, int vertex2, double weight)
{
    if (adjacency_matrix[vertex1][vertex2] == 0)
    {
        if (weight != 0)
        {
            edges_num_++;
        }
    }
    else
    {
        if (weight == 0)
        {
            edges_num_--;
        }
    }
    adjacency_matrix[vertex1][vertex2] = weight;
    adjacency_matrix[vertex2][vertex1] = weight;
}

double Graph::get_random_value()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);
    return dis(gen);
}

int Graph::get_size()
{
    return vertex_num_;
}

Graph Graph::get_MST_Kruskal()
{
    Graph MST(vertex_num_);
    std::vector<int> ranks(vertex_num_);
    std::vector<int> previous(vertex_num_);

    for (int i = 0; i < vertex_num_; i++)
    {
        previous[i] = i;
        ranks[i] = 0;
    }

    std::vector<Edge> edges = get_sorted_edges();
    for (const auto &edge : edges)
    {
        if (find(edge.vertex1, previous) != find(edge.vertex2, previous))
        {
            MST.modify_edge(edge.vertex1, edge.vertex2, edge.weight);
            set_union(edge.vertex1, edge.vertex2, previous, ranks);
        }
        if (MST.edges_num_ == MST.vertex_num_ - 1)
        {
            break;
        }
    }
    return MST;
}

Graph Graph::get_MST_Prim()
{
    Graph MST(vertex_num_);
    std::vector<double> costs(vertex_num_, std::numeric_limits<double>::max());
    std::vector<int> previous(vertex_num_, -1);
    std::vector<bool> visited(vertex_num_, false);

    costs[0] = 0;

    for (int i = 0; i < vertex_num_ - 1; i++)
    {
        int u = min_key(costs, visited);
        visited[u] = true;
        for (int i = 0; i < vertex_num_; i++)
        {
            if (adjacency_matrix[u][i] != 0 && visited[i] == false && adjacency_matrix[u][i] < costs[i])
            {
                previous[i] = u;
                costs[i] = adjacency_matrix[u][i];
            }
        }
    }

    for (int i = 1; i < vertex_num_; i++)
    {
        MST.modify_edge(previous[i], i, adjacency_matrix[previous[i]][i]);
    }
    return MST;
}

int Graph::min_key(std::vector<double> costs, std::vector<bool> visited)
{
    double min = std::numeric_limits<double>::max();
    int min_index;

    for (int i = 0; i < vertex_num_; i++)
    {
        if (visited[i] == false && costs[i] < min)
        {
            min = costs[i];
            min_index = i;
        }
    }

    return min_index;
}

int Graph::find(int vertex, std::vector<int> previous)
{
    while (vertex != previous[vertex])
    {
        vertex = previous[vertex];
    }
    return vertex;
}

void Graph::set_union(int vertex1, int vertex2, std::vector<int> &previous, std::vector<int> &ranks)
{
    int identifier1 = find(vertex1, previous);
    int identifier2 = find(vertex2, previous);
    if (identifier1 == identifier2)
    {
        return;
    }
    if (ranks[identifier1] > ranks[identifier2])
    {
        previous[identifier2] = identifier1;
    }
    else
    {
        previous[identifier1] = identifier2;
        if (ranks[identifier1] == ranks[identifier2])
        {
            ranks[identifier2]++;
        }
    }
}

std::vector<Edge> Graph::get_sorted_edges()
{
    std::vector<Edge> result;

    for (int i = 0; i < vertex_num_; i++)
    {
        for (int j = i + 1; j < vertex_num_; j++)
        {
            result.push_back(Edge(i, j, adjacency_matrix[i][j]));
        }
    }

    std::sort(result.begin(), result.end(), [](const Edge &a, const Edge &b)
              { return a.weight < b.weight; });
    return result;
}

void Graph::print_adjacency_matrix()
{
    std::cout << std::setprecision(3) << std::fixed;
    for (int i = 0; i < vertex_num_; i++)
    {
        for (int j = 0; j < vertex_num_; j++)
        {
            std::cout << adjacency_matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}