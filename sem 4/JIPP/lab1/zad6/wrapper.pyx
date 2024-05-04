cdef extern from "library.h":
    ctypedef struct solution:
        bint exists
        int x
        int y

    int factorial_loop(int n)
    int gcd_loop(int a, int b)
    solution diophantine_loop(int a, int b, int c)
    int factorial_rec(int n)
    int gcd_rec(int a, int b)
    solution diophantine_rec(int a, int b, int c)

cdef class Solution_loop:
    cdef solution s 

    def __init__(self, a, b, c):
        self.s = diophantine_loop(a, b, c)

    @property
    def exists(self):
       return self.s.exists

    @property
    def x(self):
        return self.s.x
    
    @property
    def y(self):
        return self.s.y

cdef class Solution_rec:
    cdef solution s 

    def __init__(self, a, b, c):
        self.s = diophantine_rec(a, b, c)

    @property
    def exists(self):
       return self.s.exists

    @property
    def x(self):
        return self.s.x
    
    @property
    def y(self):
        return self.s.y

def python_factorial_loop(int n):
    return factorial_loop(n)

def python_gcd_loop(int a, int b):
    return gcd_loop(a, b)

def python_factorial_rec(int n):
    return factorial_rec(n)

def python_gcd_rec(int a, int b):
    return gcd_rec(a, b)

