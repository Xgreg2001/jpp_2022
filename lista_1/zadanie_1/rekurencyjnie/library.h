#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct diophantine_solution
{
    int64_t x;
    int64_t y;
    bool solution_exist;
} diophantine_solution;


uint64_t factorial(uint64_t n);

int64_t gcd(int64_t a, int64_t b);

diophantine_solution linear_equation(int64_t a, int64_t b, int64_t c);