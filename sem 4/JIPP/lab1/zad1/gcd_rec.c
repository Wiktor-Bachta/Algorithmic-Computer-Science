#include "library.h"

int gcd_rec(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd_rec(b, a % b);
}