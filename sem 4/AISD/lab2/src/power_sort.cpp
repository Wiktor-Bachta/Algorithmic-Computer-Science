#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>

std::vector<int> merge_sort(std::vector<int> &A);
std::vector<int> merge(std::vector<int> &A, std::vector<int> &B);
bool less_than(int a, int b);
std::vector<int> power_sort(std::vector<int> &A);
int extend_run_right(std::vector<int> &A, int i);
int node_power(int s1, int e1, int s2, int e2, int n);
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

std::vector<int> power_sort(std::vector<int> &A)
{
    int n = A.size();
    std::vector<std::vector<int>> runs;
    std::vector<int> powers;
    std::vector<int> v;

    int s1 = 0;
    int e1 = extend_run_right(A, s1);

    while (e1 < n)
    {
        int s2 = e1 + 1;
        int e2 = extend_run_right(A, s2);
        int p = node_power(s1, e1, s2, e2, n);

        while (!powers.empty() && powers.back() > p)
        {
            powers.pop_back();
            v = std::vector<int>(A.begin() + s1, A.begin() + e1 + 1);
            if (!runs.empty())
            {
                v = merge(runs.back(), v);
                runs.pop_back();
            }
        }

        runs.push_back(v);
        powers.push_back(p);
        s1 = s2;
        e1 = e2;
    }

    v = std::vector<int>(A.begin() + s1, A.begin() + e1 + 1);

    while (!runs.empty())
    {
        v = merge(runs.back(), v);
        runs.pop_back();
    }

    return v;
}


int extend_run_right(std::vector<int> &A, int i)
{
    while (i < A.size() - 1 && less_than(A[i], A[i + 1]))
    {
        i++;
    }
    return i;
}

int node_power(int s1, int e1, int s2, int e2, int n)
{
    int n1 = e1 - s1 + 1;
    int n2 = e2 - s2 + 1;
    int l = 0;
    float a = (s1 + n1 / 2 - 1) / n;
    float b = (s2 + n2 / 2 - 1) / n;

    while (std::floor(a * std::pow(2, l)) == std::floor(b * std::pow(2, l)))
    {
        l++;
    }

    return l;
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
