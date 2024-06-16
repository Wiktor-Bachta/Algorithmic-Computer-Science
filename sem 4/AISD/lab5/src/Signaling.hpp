#ifndef SIGNALING_HPP
#define SIGNALING_HPP

#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

typedef struct Solution
{
    std::vector<int> ordered_children;
    int time;
    Solution(int time) : ordered_children(std::vector<int>()), time(time) {}
} Solution;

class Signaling
{
public:
    static std::vector<Solution> get_solution(int root_vertex, Graph graph);

private:
    static std::vector<std::vector<int>> get_children_list(int root_vertex, Graph graph);
    static std::vector<Solution> get_solution(int root_vertex, std::vector<std::vector<int>> children_list);
    static void solve(int vertex, std::vector<std::vector<int>> children_list, std::vector<Solution> &solutions);
};

#endif