#include "Graph.hpp"
#include "Signaling.hpp"
#include <fstream>
#include <iostream>
#include <limits>

int MIN_N = 50;
int MAX_N = 1000;
int STEP = 50;
int REPETITIONS = 10;

int main(void)
{
    std::ofstream outfile;

    outfile.open("./data/rounds.txt");

    outfile << "n,min,max,avg\n";

    for (int n = MIN_N; n <= MAX_N; n += STEP)
    {
        double all_rounds = 0;
        double max_rounds = 0;
        double min_rounds = 0;

        for (int i = 0; i < REPETITIONS; i++)
        {
            Graph graph(n);
            graph.generate_random_full_graph();
            Graph MST = graph.get_MST_Prim();

            int curr_min = std::numeric_limits<int>::max();
            int curr_max = std::numeric_limits<int>::min();

            for (int j = 0; j < n; j++)
            {
                int rounds = Signaling::get_solution(j, MST)[j].time;
                all_rounds += rounds;
                if (curr_min > rounds)
                {
                    curr_min = rounds;
                }
                if (curr_max < rounds)
                {
                    curr_max = rounds;
                }
            }
            min_rounds += curr_min;
            max_rounds += curr_max;
        }
        min_rounds /= REPETITIONS;
        max_rounds /= REPETITIONS;
        all_rounds /= (REPETITIONS * n);

        outfile << n << "," << min_rounds << "," << max_rounds << "," << all_rounds << "\n";
        outfile.flush();
        std::cout << "n = " << n << " done\n";
    }
    outfile.close();
}