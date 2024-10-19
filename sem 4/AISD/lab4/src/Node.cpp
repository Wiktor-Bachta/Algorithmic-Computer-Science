#include "Node.hpp"

Node::Node(int value) : value(value), left(nullptr), right(nullptr), parent(nullptr), color(red) {}

Node::~Node() {}