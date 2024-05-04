#ifndef LIBADA_H
#define LIBADA_H

typedef struct Solution {
    int exists;
    int x;
    int y;
} Solution;

extern int factorial_loop(int n);
extern int gcd_loop(int *a, int *b);
extern Solution diophantine_loop(int *a, int *b, int *c);
extern int factorial_rec(int n);
extern int gcd_rec(int a, int b);
extern Solution diophantine_rec(int *a, int *b, int *c);

#endif 
