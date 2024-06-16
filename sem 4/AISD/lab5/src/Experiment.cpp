#include "Graph.hpp"
#include <chrono>
#include <fstream>
#include <iostream>

int MIN_N = 10;
int MAX_N = 1000;
int STEP = 10;
int REPETITIONS = 10;

int main(void)
{
    std::ofstream outfile;

    outfile.open("./data/times.txt");

    outfile << "n,prim,kruskal\n";

    for (int n = MIN_N; n <= MAX_N; n += STEP)
    {
        double avg_time_kruskal = 0;
        double avg_time_prim = 0;

        for (int i = 0; i < REPETITIONS; i++)
        {
            Graph graph(n);
            graph.generate_random_full_graph();

            auto start = std::chrono::high_resolution_clock::now();
            graph.get_MST_Kruskal();
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::nano> elapsed = end - start;
            avg_time_kruskal += elapsed.count();

            start = std::chrono::high_resolution_clock::now();
            graph.get_MST_Prim();
            end = std::chrono::high_resolution_clock::now();
            elapsed = end - start;
            avg_time_prim += elapsed.count();
        }
        avg_time_kruskal /= REPETITIONS;
        avg_time_prim /= REPETITIONS;

        outfile << n << "," << avg_time_prim << "," << avg_time_kruskal << "\n";
        std::cout << "n = " << n << " done\n";
    }
    outfile.close();
}