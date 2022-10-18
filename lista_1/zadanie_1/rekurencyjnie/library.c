#include "library.h"

uint64_t factorial(const uint64_t n){
    if (n == 1){
        return 1;
    }

    return n * factorial(n - 1);
}

int64_t gcd(int64_t a, int64_t b){

    if (b != 0)
        return gcd(b, a % b);
    else
        return a;
}

static int64_t extended_gcd(int64_t a, int64_t b, int64_t* x, int64_t* y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int64_t x1, y1;
    int64_t d = extended_gcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - y1 * (a / b);
    return d;
}

diophantine_solution linear_equation(int64_t a, int64_t b, int64_t c){
    int64_t x0 = 0;
    int64_t y0 = 0;

    if (a == 0 && b == 0){
        if (c == 0){
            return (diophantine_solution){0, 0, true};
        } else {
            return (diophantine_solution){0, 0, false};
        }
    }

    int64_t g = extended_gcd(llabs(a), llabs(b), &x0, &y0);
    if (c % g != 0) {
        return (diophantine_solution){0, 0, false};
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return (diophantine_solution){x0, y0, true};
}

