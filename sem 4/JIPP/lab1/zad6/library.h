#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct solution {
    bool exists;
    int x;
    int y;
} solution;

int factorial_loop(int n);

int gcd_loop(int a, int b);

solution diophantine_loop(int a, int b, int c);

int factorial_rec(int n);

int gcd_rec(int a, int b);

solution diophantine_rec(int a, int b, int c);

#endif 