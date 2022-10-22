#include "library.h"

uint64_t factorial(const uint64_t n)
{
    uint64_t acc = 1;
    for (uint64_t i = 1; i <= n; i++)
    {
        acc *= i;
    }
    return acc;
}

int64_t gcd(int64_t a, int64_t b)
{
    a = (a > 0) ? a : -a;
    b = (b > 0) ? b : -b;

    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }

    return a;
}

static int64_t extended_gcd(int64_t a, int64_t b, int64_t *x, int64_t *y)
{
    *x = 1;
    *y = 0;

    if (b == 0)
    {
        return a;
    }

    int64_t x1 = 0, y1 = 1, a1 = a, b1 = b;

    while (b1 != 0)
    {
        int64_t q = a1 / b1;

        int64_t temp = *x;
        *x = x1;
        x1 = temp - q * x1;

        temp = *y;
        *y = y1;
        y1 = temp - q * y1;

        temp = a1;
        a1 = b1;
        b1 = temp - q * b1;
    }
    return a1;
}

diophantine_solution linear_equation(int64_t a, int64_t b, int64_t c)
{
    int64_t x0 = 0;
    int64_t y0 = 0;

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

    int64_t g = extended_gcd(llabs(a), llabs(b), &x0, &y0);

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
