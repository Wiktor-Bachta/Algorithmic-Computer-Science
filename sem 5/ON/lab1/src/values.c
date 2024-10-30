#include <stdio.h>
#include <float.h> 

int main() {

    printf("Epsilon float (FLT_EPSILON): %e\n", FLT_EPSILON);
    printf("Epsilon double (DBL_EPSILON): %e\n", DBL_EPSILON);

    printf("Maksymalna wartość float (FLT_MAX): %e\n", FLT_MAX);
    printf("Maksymalna wartość double (DBL_MAX): %e\n", DBL_MAX);

    return 0;
}
