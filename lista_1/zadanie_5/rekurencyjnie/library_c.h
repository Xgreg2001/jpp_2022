#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct diophantine_solution
{
    int x;
    int y;
    bool solution_exist;
} diophantine_solution;

int factorial(int n);

int gcd(int a, int b);

diophantine_solution linear_equation(int a, int b, int c);