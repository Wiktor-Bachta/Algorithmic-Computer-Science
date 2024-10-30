#include "Graph.hpp"
#include "searches.hpp"
#include "topological_sort_kahn.hpp"
#include "connected_components_tarjan.hpp"
#include "bipartite_dfs.hpp"
#include <chrono>

int main(void)
{
    std::ofstream out_file("./results.txt");
    out_file << "nazwa, skierowany, |V| + |E|, czas\n";
    out_file.close();

    std::vector<std::string> filenames = {"g3-1.txt", "g3-2.txt", "g3-3.txt", "g3-4.txt", "g3-5.txt", "g3-6.txt"};

    for (const auto &filename : filenames)
    {
        Graph g("./aod_testy1/3/" + filename);
        std::string directed;
        if (g.is_directed)
        {
            directed = "skierowany";
        }
        else
        {
            directed = "nieskierowany";
        }
        auto begin = std::chrono::high_resolution_clock::now();
        dfs(g, false, false);
        auto end = std::chrono::high_resolution_clock::now();

        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();

        out_file.open("./results.txt", std::ios_base::app);
        out_file << filename << "," << directed << "," << g.edges_num + g.vertex_num << "," << time << "\n";
        out_file.close();
    }

    out_file.open("./results.txt", std::ios_base::app);
    out_file << "nazwa, skierowany, |V| + |E|, czas\n";
    out_file.close();

    filenames = {"g3-1.txt", "g3-2.txt", "g3-3.txt", "g3-4.txt", "g3-5.txt", "g3-6.txt"};

    for (const auto &filename : filenames)
    {
        Graph g("./aod_testy1/3/" + filename);
        std::string directed;
        if (g.is_directed)
        {
            directed = "skierowany";
        }
        else
        {
            directed = "nieskierowany";
        }
        auto begin = std::chrono::high_resolution_clock::now();
        bfs(g, false, false);
        auto end = std::chrono::high_resolution_clock::now();

        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();

        out_file.open("./results.txt", std::ios_base::app);
        out_file << filename << "," << directed << "," << g.edges_num + g.vertex_num << "," << time << "\n";
        out_file.close();
    }

    out_file.open("./results.txt", std::ios_base::app);
    out_file << "nazwa, skierowany, |V| + |E|, czas\n";
    out_file.close();

    filenames = {"g2a-1.txt", "g2b-1.txt", "g2a-2.txt", "g2b-2.txt", "g2a-3.txt", "g2b-3.txt",
                 "g2a-4.txt", "g2b-4.txt", "g2a-5.txt", "g2b-5.txt", "g2a-6.txt", "g2b-6.txt"};

    for (const auto &filename : filenames)
    {
        Graph g("./aod_testy1/2/" + filename);
        std::string directed;
        if (g.is_directed)
        {
            directed = "skierowany";
        }
        else
        {
            directed = "nieskierowany";
        }
        auto begin = std::chrono::high_resolution_clock::now();
        is_acyclic(g, false);
        auto end = std::chrono::high_resolution_clock::now();

        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();

        out_file.open("./results.txt", std::ios_base::app);
        out_file << filename << "," << directed << "," << g.edges_num + g.vertex_num << "," << time << "\n";
        out_file.close();
    }

    out_file.open("./results.txt", std::ios_base::app);
    out_file << "nazwa, skierowany, |V| + |E|, czas\n";
    out_file.close();

    filenames = {"g3-1.txt", "g3-2.txt", "g3-3.txt", "g3-4.txt", "g3-5.txt"};//, "g3-6.txt"};

    for (const auto &filename : filenames)
    {
        Graph g("./aod_testy1/3/" + filename);
        std::string directed;
        if (g.is_directed)
        {
            directed = "skierowany";
        }
        else
        {
            directed = "nieskierowany";
        }
        auto begin = std::chrono::high_resolution_clock::now();
        get_connected_components(g);
        auto end = std::chrono::high_resolution_clock::now();

        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();

        out_file.open("./results.txt", std::ios_base::app);
        out_file << filename << "," << directed << "," << g.edges_num + g.vertex_num << "," << time << "\n";
        out_file.close();
    }

    out_file.open("./results.txt", std::ios_base::app);
    out_file << "nazwa, skierowany, |V| + |E|, czas\n";
    out_file.close();

    filenames = {"d4a-1.txt", "d4b-1.txt", "u4a-1.txt", "u4b-1.txt",
                 "d4a-2.txt", "d4b-2.txt", "u4a-2.txt", "u4b-2.txt",
                 "d4a-3.txt", "d4b-3.txt", "u4a-3.txt", "u4b-3.txt",
                 "d4a-4.txt", "d4b-4.txt", "u4a-4.txt", "u4b-4.txt",
                 "d4a-5.txt", "d4b-5.txt", "u4a-5.txt", "u4b-5.txt",
                 "d4a-6.txt", "d4b-6.txt", "u4a-6.txt", "u4b-6.txt"};

    for (const auto &filename : filenames)
    {
        Graph g("./aod_testy1/4/" + filename);
        std::string directed;
        if (g.is_directed)
        {
            directed = "skierowany";
        }
        else
        {
            directed = "nieskierowany";
        }
        auto begin = std::chrono::high_resolution_clock::now();
        is_bapartite(g, false);
        auto end = std::chrono::high_resolution_clock::now();

        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();

        out_file.open("./results.txt", std::ios_base::app);
        out_file << filename << "," << directed << "," << g.edges_num + g.vertex_num << "," << time << "\n";
        out_file.close();
    }
}
