#include "library.h"

solution diophantine_recursive(int a, int b, int x, int y, int u, int v);

solution diophantine_rec(int a, int b, int c)
{
    solution result;
    result.exists = false;
    int gcd_ab = gcd_rec(a, b);

    if (c % gcd_ab != 0)
    {
        return result;
    }

    result = diophantine_recursive(a, b, 0, 1, 1, 0);

    int factor = c / gcd_ab;
    result.x *= factor;
    result.y *= factor;
    return result;
}

solution diophantine_recursive(int a, int b, int x, int y, int u, int v)
{
    if (a == 0)
    {
        solution result;
        result.exists = true;
        result.x = x;
        result.y = y;
        return result;
    }

    int r = b % a;
    int q = b / a;
    int m = x - u * q;
    int n = y - v * q;

    return diophantine_recursive(r, a, u, v, m, n);
}