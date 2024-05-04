#include <stdio.h>
#include "libada.h"

void test_factorial_loop() {
    printf("Testing factorial_loop...\n");
    printf("Factorial of 0: %d\n", factorial_loop(0)); // Expected: 1
    printf("Factorial of 5: %d\n", factorial_loop(5)); // Expected: 120
}

void test_gcd_loop() {
    printf("Testing gcd_loop...\n");
    int a = 12, b = 18;
    printf("GCD of %d and %d: %d\n", a, b, gcd_loop(&a, &b)); // Expected: 6

    a = 35, b = 49;
    printf("GCD of %d and %d: %d\n", a, b, gcd_loop(&a, &b)); // Expected: 7
}

void test_diophantine_loop() {
    printf("Testing diophantine_loop...\n");
    int a = 2, b = 3, c = 5;
    Solution result = diophantine_loop(&a, &b, &c);
    printf("Diophantine solution: exists=%d, x=%d, y=%d\n", result.exists, result.x, result.y); // Expected: exists=1, x=5, y=-3
}

void test_factorial_rec() {
    printf("Testing factorial_rec...\n");
    printf("Factorial of 0: %d\n", factorial_rec(0)); // Expected: 1
    printf("Factorial of 5: %d\n", factorial_rec(5)); // Expected: 120
}

void test_gcd_rec() {
    printf("Testing gcd_rec...\n");
    printf("GCD of 12 and 18: %d\n", gcd_rec(12, 18)); // Expected: 6
    printf("GCD of 35 and 49: %d\n", gcd_rec(35, 49)); // Expected: 7
}

void test_diophantine_rec() {
    printf("Testing diophantine_rec...\n");
    int a = 2, b = 3, c = 5;
    Solution result = diophantine_rec(&a, &b, &c);
    printf("Diophantine solution: exists=%d, x=%d, y=%d\n", result.exists, result.x, result.y); // Expected: exists=1, x=5, y=-3
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


// gcc -shared -o libada.so libada.o
// gcc -o test test.c -L. -lada -I. -lm -lgnat -lgcc_s -Wl,-rpath,$PWD
