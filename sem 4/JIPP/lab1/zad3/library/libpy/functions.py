class Solution:
    exists: bool
    x: int
    y: int


def factorial_loop(n: int) -> int:
    result = 1
    for i in range(2, n + 1):
        result *= i
    return result


def gcd_loop(a: int, b: int) -> int:
    while b != 0:
        a, b = b, a % b
    return a


def diophatine_loop(a: int, b: int, c: int) -> Solution:
    result = Solution()
    result.exists = False

    gcd_ab = gcd_loop(a, b)

    if c % gcd_ab != 0:
        return result

    x, y, u, v = 0, 1, 1, 0

    while a != 0:
        r = b % a
        q = b // a
        m = x - u * q
        n = y - v * q

        b, a = a, r
        x, y = u, v
        u, v = m, n

    factor = c / gcd_ab

    result.exists = True
    result.x = int(x * factor)
    result.y = int(y * factor)
    return result

def factorial_rec(n: int) -> int:
    if n == 0:
        return 1
    return n * factorial_rec(n-1)


def gcd_rec(a: int, b: int) -> int:
    if b == 0:
        return a
    return gcd_rec(b, a % b)


def diophatine_rec(a: int, b: int, c: int) -> Solution:
    def diophantine_recursive(a: int, b: int, x: int, y: int, u: int, v: int) -> int:
        if a == 0:
            result = Solution()
            result.exists = True
            result.x = x
            result.y = y
            return result

        r = b % a
        q = b // a
        m = x - u * q
        n = y - v * q

        return diophantine_recursive(r, a, u, v, m, n)

    result = Solution()
    result.exists = False

    gcd_ab = gcd_rec(a, b)

    if c % gcd_ab != 0:
        return result

    result = diophantine_recursive(a, b, 0, 1, 1, 0)

    factor = c / gcd_ab
    result.x = int(result.x * factor)
    result.y = int(result.y * factor)
    return result
