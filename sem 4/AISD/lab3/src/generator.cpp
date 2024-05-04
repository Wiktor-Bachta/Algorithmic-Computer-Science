#include <iostream>
#include <string.h>
#include <algorithm>
#include <random>

void generate_random(int *array, int n);

int main(int argc, char *argv[])
{
    if (argc < 2 || argc > 4)
    {
        std::cout << "Prawidłowe użycie: ./generator (select/binary/-i/-d) (one/half/random)/(start/middle/out) n\n";
        return 0;
    }

    int n = atoi(argv[argc - 1]);

    if (n <= 0)
    {
        std::cout << "Prawidłowe użycie: ./generator (select/binary/-i/-d) (one/half/random)/(start/middle/out) n\n";
        return 0;
    }

    int sequence[n];
    generate_random(sequence, n);

    int k = -1;

    if (strcmp(argv[1], "select") == 0 && argc == 4)
    {
        if (strcmp(argv[2], "one") == 0)
        {
            k = 1;
        }

        else if (strcmp(argv[2], "half") == 0)
        {
            k = n / 2;
        }

        else if (strcmp(argv[2], "random") == 0)
        {
            std::random_device rand_dev;
            std::mt19937 generator(rand_dev());
            std::uniform_int_distribution<int> distr(1, n);
            k = distr(generator);
        }
        else
        {
            std::cout << "Prawidłowe użycie: ./generator (select/binary/-i/-d) (one/half/random)/(start/middle/out) n\n";
            return 0;
        }
    }

    else if (strcmp(argv[1], "binary") == 0 && argc == 4)
    {
        std::sort(sequence, sequence + n);
        if (strcmp(argv[2], "start") == 0)
        {
            k = sequence[0];
        }
        else if (strcmp(argv[2], "middle") == 0)
        {
            k = sequence[n / 2];
        }
        else if (strcmp(argv[2], "out") == 0)
        {
            k = sequence[n - 1] + 1;
        }
        else if (strcmp(argv[2], "random") == 0)
        {
            std::random_device rand_dev;
            std::mt19937 generator(rand_dev());
            std::uniform_int_distribution<int> distr(0, n - 1);
            k = sequence[distr(generator)];
        }
        else
        {
            std::cout << "Prawidłowe użycie: ./generator (select/binary/-i/-d) (one/half/random)/(start/middle/out) n\n";
            return 0;
        }
    }

    else if (strcmp(argv[1], "-d") == 0 && argc == 3)
    {
        std::sort(sequence, sequence + n);
        std::reverse(sequence, sequence + n);
    }

    else if (strcmp(argv[1], "-i") == 0 && argc == 3)
    {
        std::sort(sequence, sequence + n);
    }

    else if (strcmp(argv[1], "-n") == 0 && argc == 3)
    {
        }

    else if (argc != 2)
    {
        std::cout << "Prawidłowe użycie: ./generator (select/binary/-i/-d) (one/half/random)/(start/middle/out) n\n";
        return 0;
    }

    std::cout << n;

    if (k != -1)
    {
        std::cout << " " << k;
    }

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