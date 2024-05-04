#include <iostream>
#include <algorithm>
#include <iomanip>

int randomized_select(int A[], int p, int q, int i);
int partition(int A[], int p, int q);
bool less_than(int a, int b);
void swap(int A[], int i, int j);
void print_array(int A[], int n);

int swaps = 0;
int comparisons = 0;
int n;

int main(void)
{
    std::cin >> n;
    int k;
    std::cin >> k;
    int A[n];
    int B[n];
    int C[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> A[i];
        B[i] = A[i];
        C[i] = B[i];
    }

    int res = randomized_select(A, 0, n - 1, k);
    std::sort(C, C + n);

    if (n <= 50)
    {
        std::cout << "\npoczątkowy stan tablicy: ";
        print_array(B, n);

        std::cout << "końcowy stan tablicy:    ";
        print_array(A, n);

        std::cout << std::setw(2) << k << "-statystyka pozycyjna: " << std::setw(2) << res << "\n";

        std::cout << "posortowana tablica:     ";
        print_array(C, n);
    }

    std::cout << "liczba porównań:         " << comparisons << "\n";
    std::cout << "liczba przestawień:      " << swaps << "\n";

    if (res != C[k - 1])
    {
        std::cout << "coś poszło nie tak\n";
    }

    return 0;
}

int randomized_select(int A[], int p, int q, int i)
{
    if (n <= 50)
    {
        print_array(A, n);
    }
    if (p == q)
    {
        return A[p];
    }
    int r = partition(A, p, q);
    int k = r - p + 1;
    if (i == k)
    {
        return A[r];
    }
    if (i < k)
    {
        return randomized_select(A, p, r - 1, i);
    }
    return randomized_select(A, r + 1, q, i - k);
}

int partition(int A[], int p, int q)
{
    int pivot = A[q];
    int i = p;

    for (int j = p; j < q; j++)
    {
        if (less_than(A[j], pivot))
        {
            swap(A, j, i);
            i++;
        }
    }
    swap(A, i, q);
    return i;
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
    if (i != j)
    {
        swaps++;
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
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
