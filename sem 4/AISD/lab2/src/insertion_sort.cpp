#include <iostream>
#include <iomanip>
#include <algorithm>

void insertion_sort(int A[], int n);
bool less_than(int a, int b);
void swap(int A[], int i, int j);
void print_array(int A[], int n);
bool check_sorted(int before[], int after[]);

int comparisons = 0;
int swaps = 0;
int n;

int main(void)
{
    std::cin >> n;

    int A[n];
    int B[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> A[i];
        B[i] = A[i];
    }

    if (n < 40)
    {
        print_array(A, n);
        std::cout << "\n";
    }

    insertion_sort(A, n);

    if (n < 40)
    {
        std::cout << "\n";
        print_array(B, n);
        print_array(A, n);
    }

    std::cout << "Liczba porównań: " << comparisons << "\n";
    std::cout << "Liczba przestawień: " << swaps << "\n";

    if (!check_sorted(B, A))
    {
        std::cout << "Ups, coś poszło nie tak w sortowaniu\n";
    }

    return 0;
}

void insertion_sort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;

        while (j >= 0 && less_than(A[j + 1], A[j]))
        {
            swap(A, j, j + 1);
            j = j - 1;
        }
        if (n < 40)
        {
            print_array(A, n);
        }
    }
}

bool less_than(int a, int b)
{
    comparisons++;
    if (a < b)
    {
        return true;
    }
    return false;
}

void swap(int A[], int i, int j)
{
    swaps++;
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
    return;
}

void print_array(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << std::setw(2) << A[i] << " ";
    }
    std::cout << "\n";
    return;
}

bool check_sorted(int before[], int after[])
{
    std::sort(before, before + n);
    for (int i = 0; i < n; i++)
    {
        if (before[i] != after[i])
        {
            return false;
        }
    }
    return true;
}