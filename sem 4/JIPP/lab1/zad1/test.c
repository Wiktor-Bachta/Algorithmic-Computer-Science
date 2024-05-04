#include <stdio.h>
#include <assert.h>
#include "library.h"

void test_factorial_loop() {
    assert(factorial_loop(0) == 1);
    assert(factorial_loop(1) == 1);
    assert(factorial_loop(5) == 120);
    assert(factorial_loop(10) == 3628800);
    assert(factorial_loop(12) == 479001600);
    printf("factorial_loop tests passed.\n");
}

void test_gcd_loop() {
    assert(gcd_loop(8, 12) == 4);
    assert(gcd_loop(17, 23) == 1);
    assert(gcd_loop(15, 25) == 5);
    assert(gcd_loop(24, 36) == 12);
    assert(gcd_loop(18, 9) == 9);
    printf("gcd_loop tests passed.\n");
}

void test_diophantine_loop() {
    solution sol = diophantine_loop(3, 5, 12);
    assert(sol.exists && (3 * sol.x + 5 * sol.y == 12));
    sol = diophantine_loop(7, 13, 100);
    assert(sol.exists && (7 * sol.x + 13 * sol.y == 100));
    sol = diophantine_loop(4, 6, 25);
    assert(!sol.exists);
    sol = diophantine_loop(10, 15, 40);
    assert(sol.exists && (10 * sol.x + 15 * sol.y == 40));
    sol = diophantine_loop(16, 8, 64);
    assert(sol.exists && (8 * sol.x + 8 * sol.y == 64));
    printf("diophantine_loop tests passed.\n");
}

void test_factorial_rec() {
    assert(factorial_rec(0) == 1);
    assert(factorial_rec(1) == 1);
    assert(factorial_rec(5) == 120);
    assert(factorial_rec(10) == 3628800);
    assert(factorial_rec(12) == 479001600);
    printf("factorial_rec tests passed.\n");
}

void test_gcd_rec() {
    assert(gcd_rec(8, 12) == 4);
    assert(gcd_rec(17, 23) == 1);
    assert(gcd_rec(15, 25) == 5);
    assert(gcd_rec(24, 36) == 12);
    assert(gcd_rec(18, 9) == 9);
    printf("gcd_rec tests passed.\n");
}

void test_diophantine_rec() {
    solution sol = diophantine_rec(3, 5, 12);
    assert(sol.exists && (3 * sol.x + 5 * sol.y == 12));
    sol = diophantine_rec(7, 13, 100);
    assert(sol.exists && (7 * sol.x + 13 * sol.y == 100));
     sol = diophantine_rec(4, 6, 25);
    assert(!sol.exists);
    sol = diophantine_rec(10, 15, 40);
    assert(sol.exists && (10 * sol.x + 15 * sol.y == 40));
    sol = diophantine_rec(16, 8, 64);
    assert(sol.exists && (8 * sol.x + 8 * sol.y == 64));
    printf("diophantine_rec tests passed.\n");
}

int main() {
    test_factorial_loop();
    test_gcd_loop();
    test_diophantine_loop();
    test_factorial_rec();
    test_gcd_rec();
    test_diophantine_rec();
    return 0;
}
