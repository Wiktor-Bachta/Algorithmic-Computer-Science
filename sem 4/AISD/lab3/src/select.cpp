#include <iostream>
#include <algorithm>
#include <iomanip>

int select(int A[], int p, int q, int i);
int partition(int A[], int p, int q, int pivot);
bool less_than(int a, int b);
bool equal(int a, int b);
void swap(int A[], int i, int j);
void print_array(int A[], int n);
void insertion_sort(int A[], int n);
int median(int A[], int p, int q);

int swaps = 0;
int comparisons = 0;
int n;
int magic = 5;
int *Array;

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        magic = std::stoi(argv[1]);
    }

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

    Array = A;

    int res = select(A, 0, n - 1, k);
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

int select(int A[], int p, int q, int i)
{
    if (n <= 50 && Array == A)
    {
        print_array(Array, n);
    }
    if (p == q)
    {
        return A[p];
    }

    int len = q - p + 1;
    int num_fives = (len + magic - 1) / magic;
    int medians[num_fives];
    for (int j = p; j <= q; j += magic)
    {
        medians[(j - p) / magic] = median(A, j, std::min(j + magic - 1, q));
    }

    int median_of_medians = select(medians, 0, num_fives - 1, num_fives / 2);

    int r = partition(A, p, q, median_of_medians);
    int k = r - p + 1;
    if (i == k)
    {
        return A[r];
    }
    if (i < k)
    {
        return select(A, p, r - 1, i);
    }
    return select(A, r + 1, q, i - k);
}


int partition(int A[], int p, int q, int pivot)
{
    int i = p;
    bool pivot_moved = false;

    for (int j = p; j < q; j++)
    {
        if (less_than(A[j], pivot))
        {
            swap(A, j, i);
            i++;
        }
        else if (!pivot_moved && equal(A[j], pivot))
        {
            swap(A, j, q);
            pivot_moved = true;
            j--;
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

bool equal(int a, int b)
{
    comparisons++;
    return a == b;
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
    }
}

int median(int A[], int p, int q)
{
    int len = q - p + 1;
    int B[len];
    for (int i = p; i <= q; i++)
    {
        B[i - p] = A[i];
    }
    insertion_sort(B, len);
    return B[len / 2];
}
