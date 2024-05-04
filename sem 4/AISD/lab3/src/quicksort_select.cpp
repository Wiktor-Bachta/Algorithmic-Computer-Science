#include <iostream>
#include <iomanip>
#include <algorithm>

void quick_sort(int A[], int p, int q);
int partition(int A[], int p, int q);
bool less_than(int a, int b);
bool equal(int a, int b);
void swap(int A[], int i, int j);
void print_array(int A[], int n);
bool check_sorted(int before[], int after[]);
int select(int A[], int p, int q, int i);
int partition(int A[], int p, int q, int pivot);
void insertion_sort(int A[], int n);
int median(int A[], int p, int q);

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

void quick_sort(int A[], int p, int q)
{
    if (p < q)
    {
        if (n < 40)
        {
            print_array(A, n);
        }
        int k;
        if (q - p + 1 >= 100)
        {
            int pivot = select(A, p, q, (q - p + 1) / 2);
            for (int i = p; i <= q; i++)
            {
                if (equal(A[i], pivot))
                {
                    k = i;
                    break;
                }
            }
        }
        else
        {
            k = partition(A, p, q);
        }

        quick_sort(A, p, k - 1);
        quick_sort(A, k + 1, q);
    }
    return;
}

int partition(int A[], int p, int q)
{
    int i = p;
    int pivot = A[q];

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

int select(int A[], int p, int q, int i)
{
    if (p == q)
    {
        return A[p];
    }

    int len = q - p + 1;
    int num_fives = (len + 4) / 5;
    int medians[num_fives];
    for (int j = p; j <= q; j += 5)
    {
        medians[(j - p) / 5] = median(A, j, std::min(j + 4, q));
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
