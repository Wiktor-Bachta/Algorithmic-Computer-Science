#include <iostream>
#include <string.h>
#include <algorithm>
#include <random>

void generate_random(int *array, int n);

enum mode
{
    regular,
    increasing,
    decreasing
};

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout << "Prawidłowe użycie: ./generator (-d) (-i) n\n";
        return 0;
    }

    int n = atoi(argv[1]);
    mode m = regular;

    if (strcmp(argv[1], "-d") == 0 && argc == 3)
    {
        m = decreasing;
        n = atoi(argv[2]);
    }

    else if (strcmp(argv[1], "-i") == 0)
    {
        m = increasing;
        n = atoi(argv[2]);
    }

    if (n <= 0)
    {
        std::cout << "Prawidłowe użycie: ./generator (-d) (-i) n\n;";
        return 0;
    }

    int sequence[n];
    generate_random(sequence, n);

    if (m == increasing)
    {
        std::sort(sequence, sequence + n);
    }
    else if (m == decreasing)
    {
        std::sort(sequence, sequence + n);
        std::reverse(sequence, sequence + n);
    }

    std::cout << n;

    for (int i = 0; i < n; i++)
    {
        std::cout << " " << sequence[i];
    }
    std::cout << "\n";

    return 0;
}

void generate_random(int *array, int n)
{

    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(0, 2 * n - 1);

    for (int i = 0; i < n; i++)
    {
        array[i] = distr(generator);
    }
    return;
}