#include "library.h"
#include <assert.h>
#include <stdio.h>

int main()
{
    assert(factorial(5) == 120);

    assert(gcd(12, 3) == 3);
    assert(gcd(5, 7) == 1);

    diophantine_solution sol = linear_equation(43, 7, 17);

    assert(sol.x == 17);
    assert(sol.y == -102);
    assert(sol.solution_exist == true);

    return 0;
}
