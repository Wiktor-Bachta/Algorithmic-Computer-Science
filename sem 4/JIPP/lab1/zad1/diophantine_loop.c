#include "library.h"

solution diophantine_loop(int a, int b, int c)
{
    solution result;
    result.exists = false;

    int gcd_ab = gcd_loop(a, b);

    if (c % gcd_ab != 0)
    {
        return result;
    }

    int x = 0;
    int y = 1;
    int u = 1;
    int v = 0;

    while (a != 0)
    {
        int r = b % a;
        int q = b / a;
        int m = x - u * q;
        int n = y - v * q;

        b = a;
        a = r;
        x = u;
        y = v;
        u = m;
        v = n;
    }

    int factor = c / gcd_ab;

    result.exists = true;
    result.x = x * factor;
    result.y = y * factor;
    return result;
}