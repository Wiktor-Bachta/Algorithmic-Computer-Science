#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

std::vector<int> merge_sort(std::vector<int> &A);
std::vector<int> merge(std::vector<int> &A, std::vector<int> &B);
bool less_than(int a, int b);
void print_array(const std::vector<int> &A);
bool check_sorted(const std::vector<int> &before, const std::vector<int> &after);

int comparisons = 0;
int n;

int main(void)
{
    std::cin >> n;

    std::vector<int> A(n);
    std::vector<int> B(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> A[i];
        B[i] = A[i];
    }

    if (n < 40)
    {
        print_array(A);
    }

    A = merge_sort(A);

    if (n < 40)
    {
        print_array(A);
    }

    std::cout << "Liczba porównań: " << comparisons << "\n";
    std::cout << "Liczba przestawień: 0\n";

    if (!check_sorted(B, A))
    {
        std::cout << "Ups, coś poszło nie tak w sortowaniu\n";
    }

    return 0;
}

std::vector<int> merge_sort(std::vector<int> &A)
{
    if (A.size() < 2)
    {
        return A;
    }

    int mid = A.size() / 2;
    std::vector<int> L(A.begin(), A.begin() + mid);
    std::vector<int> R(A.begin() + mid, A.end());

    L = merge_sort(L);
    R = merge_sort(R);

    return merge(L, R);
}

std::vector<int> merge(std::vector<int> &A, std::vector<int> &B)
{
    std::vector<int> res;
    std::vector<int>::size_type i = 0, j = 0;

    while (i < A.size() && j < B.size())
    {
        if (less_than(A[i], B[j]))
        {
            res.push_back(A[i]);
            i++;
        }
        else
        {
            res.push_back(B[j]);
            j++;
        }
    }

    while (i < A.size())
    {
        res.push_back(A[i]);
        i++;
    }

    while (j < B.size())
    {
        res.push_back(B[j]);
        j++;
    }

    return res;
}

bool less_than(int a, int b)
{
    comparisons++;
    return a < b;
}

void print_array(const std::vector<int> &A)
{
    for (int num : A)
    {
        std::cout << std::setw(2) << num << " ";
    }
    std::cout << "\n";
}

bool check_sorted(const std::vector<int> &before, const std::vector<int> &after)
{
    std::vector<int> temp = before;
    std::sort(temp.begin(), temp.end());
    return temp == after;
}
