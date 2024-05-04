#include <iostream>
#include <iomanip>

int binary_search(int A[], int p, int q, int v);
bool equal(int a, int b);
bool less_than(int a, int b);
void print_array(int A[], int n);

int comparisons = 0;

int main(void)
{
    int n;
    std::cin >> n;
    int v;
    std::cin >> v;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> A[i];
    }

    int found = binary_search(A, 0, n - 1, v);

    if (n <= 50)
    {
        print_array(A, n);
        std::cout << "szukana liczba: " << v << "\n";
        if (found)
        {
            std::cout << "znaleziona!\n";
        }
        else
        {
            std::cout << "nieznaleziona!\n";
        }
    }

    std::cout << "liczba porównań: " << comparisons << "\n";
}

int binary_search(int A[], int p, int q, int v)
{
    if (p > q)
    {
        return 0;
    }
    int mid = (p + q) / 2;
    if (equal(A[mid], v))
    {
        return 1;
    }
    else if (less_than(v, A[mid]))
    {
        return binary_search(A, p, mid - 1, v);
    }
    return binary_search(A, mid + 1, q, v);
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

void print_array(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << std::setw(2) << A[i] << " ";
    }
    std::cout << "\n";
    return;
}