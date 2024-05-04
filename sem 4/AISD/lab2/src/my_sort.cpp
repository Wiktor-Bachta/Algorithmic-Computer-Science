#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>

std::vector<int> my_sort(std::vector<int> &A);
std::vector<int> my_sort_rec(std::vector<std::vector<int>> runs);
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

    A = my_sort(A);

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

std::vector<int> my_sort(std::vector<int> &A)
{
    std::vector<std::vector<int>> runs;
    std::vector<int> run;
    int s = A.size();
    for (int i = 0; i < s; i++)
    {
        run.push_back(A[i]);
        if (i == s - 1 || less_than(A[i + 1], A[i]))
        {
            runs.push_back(run);
            run.clear();
        }
    }

    // sort the runs by size
    std::sort(runs.begin(), runs.end(), [](const std::vector<int> &a, const std::vector<int> &b)
              { return a.size() < b.size(); });

    int size = std::log2(s);
    int running_size = 0;
    int i = 0;
    int j = 0;
    s = runs.size();
    std::vector<std::vector<int>> groups;

    while (i < s)
    {
        running_size += runs[i].size();
        if (running_size >= size || j == s - 1)
        {
            std::vector<std::vector<int>> group(runs.begin() + i, runs.begin() + j + 1);
            groups.push_back(my_sort_rec(group));
            running_size = 0;
            i = j + 1;
        }
        j++;
    }

    return my_sort_rec(groups);
}

std::vector<int> my_sort_rec(std::vector<std::vector<int>> runs)
{
    if (runs.size() == 1)
    {
        return runs[0];
    }

    int mid = runs.size() / 2;

    std::vector<std::vector<int>> L(runs.begin(), runs.begin() + mid);
    std::vector<std::vector<int>> R(runs.begin() + mid, runs.end());

    std::vector<int> L_sorted = my_sort_rec(L);
    std::vector<int> R_sorted = my_sort_rec(R);

    return merge(L_sorted, R_sorted);
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
