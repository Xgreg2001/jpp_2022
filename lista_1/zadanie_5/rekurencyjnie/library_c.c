#include "library_c.h"

int factorial(const int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int gcd(int a, int b)
{

    if (b != 0)
        return gcd(b, a % b);
    else
        return a;
}

static int extended_gcd(int a, int b, int *x, int *y)
{
    if (b == 0)
    {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_gcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - y1 * (a / b);
    return d;
}

diophantine_solution linear_equation(int a, int b, int c)
{
    int x0 = 0;
    int y0 = 0;

    if (a == 0 && b == 0)
    {
        if (c == 0)
        {
            return (diophantine_solution){0, 0, true};
        }
        else
        {
            return (diophantine_solution){0, 0, false};
        }
    }

    int g = extended_gcd(llabs(a), llabs(b), &x0, &y0);
    if (c % g != 0)
    {
        return (diophantine_solution){0, 0, false};
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0)
        x0 = -x0;
    if (b < 0)
        y0 = -y0;
    return (diophantine_solution){x0, y0, true};
}
