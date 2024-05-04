#include <iostream>
#include <iomanip>
#include <algorithm>

void insertion_sort(int A[], int p, int q);
void quick_sort(int A[], int p, int q);
int hoare_partition(int A[], int p, int q);
bool less_than(int a, int b);
void swap(int A[], int i, int j);
void print_array(int A[], int n);
bool check_sorted(int before[], int after[]);

int comparisons = 0;
int swaps = 0;
int max_insertion = 10;
int n;

int main(int argc, char* argv[])
{
    if (argc == 2) {
        max_insertion = atoi(argv[1]);
        if (max_insertion == 0) {
            max_insertion = 10;
        }
    }

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

    quick_sort(A, 0, n - 1);

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

void insertion_sort(int A[], int p, int q)
{
    for (int i = p + 1; i <= q; i++)
    {
        int j = i - 1;

        while (j >= 0 && less_than(A[j + 1], A[j]))
        {
            swap(A, j, j + 1);
            j = j - 1;
        }
        if (n < 40)
        {
            std::cout << "I ";
            print_array(A, n);
        }
    }
}

void quick_sort(int A[], int p, int q)
{
    if (p < q)
    {
        int size = q - p + 1;
        if (size <= max_insertion)
        {
            insertion_sort(A, p, q);
        }
        else
        {
            if (n < 40)
            {
                std::cout << "Q ";
                print_array(A, n);
            }
            int k = hoare_partition(A, p, q);

            quick_sort(A, p, k);
            quick_sort(A, k + 1, q);
        }
    }
    return;
}

int hoare_partition(int A[], int p, int q)
{
    int pivot = A[(p + q) / 2];
    int i = p - 1;
    int j = q + 1;
    while (true)
    {
        do
        {
            i++;
        } while (less_than(A[i], pivot));
        do
        {
            j--;
        } while (less_than(pivot, A[j]));
        if (i >= j)
        {
            return j;
        }
        swap(A, i, j);
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
