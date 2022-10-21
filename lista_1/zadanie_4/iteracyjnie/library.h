#include <stdbool.h>

typedef struct diophantine_solution
{
    int x;
    int y;
    bool solution_exist;
} diophantine_solution;

extern int factorial(int n);

extern int gcd(int a, int b);

extern diophantine_solution linear_equation(int a, int b, int c);