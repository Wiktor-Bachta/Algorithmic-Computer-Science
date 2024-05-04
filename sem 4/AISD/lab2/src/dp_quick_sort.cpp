#include <iostream>
#include <iomanip>
#include <algorithm>

void quick_sort(int A[], int p, int q);
void count_partition(int A[], int p, int q, int *l, int *r);
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
        int l, r;
        count_partition(A, p, q, &l, &r);

        quick_sort(A, p, l - 1);
        quick_sort(A, l + 1, r - 1);
        quick_sort(A, r + 1, q);
    }
    return;
}

void count_partition(int A[], int p, int q, int *l, int *r)
{
    int lowest = 0;
    int largest = 0;

    if (less_than(A[q], A[p]))
    {
        swap(A, p, q);
    }

    int curr = p + 1;

    while (curr < q)
    {
        if (lowest >= largest)
        {
            if (less_than(A[curr], A[p]))
            {
                swap(A, curr, p);
                swap(A, curr, p + 1);
                p++;
                lowest++;
                curr++;
            }
            else if (less_than(A[q], A[curr]))
            {
                swap(A, curr, q);
                swap(A, curr, q - 1);
                q--;
                largest++;
            }
            else
            {
                curr++;
            }
        }
        else
        {
            if (less_than(A[q], A[curr]))
            {
                swap(A, curr, q);
                swap(A, curr, q - 1);
                q--;
                largest++;
            }
            else if (less_than(A[curr], A[p]))
            {
                swap(A, curr, p);
                swap(A, curr, p + 1);
                p++;
                lowest++;
                curr++;
            }
            else
            {
                curr++;
            }
        }
    }

    *l = p;
    *r = q;

    return;
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
