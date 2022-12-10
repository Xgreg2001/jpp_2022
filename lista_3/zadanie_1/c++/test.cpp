#include "finite_field.h"
#include <cassert>

int main()
{
    const long P = 1234567891;

    finite_field<P> a = finite_field<P>(1);
    finite_field<P> b = finite_field<P>(2);

    assert(a + b == finite_field<P>(3));

    assert(finite_field<P>(1234567891) == finite_field<P>(0));

    assert(finite_field<P>(3) == finite_field<P>(1) + finite_field<P>(2));
    assert(finite_field<P>(3) == finite_field<P>(1234567890) + finite_field<P>(4));

    assert(finite_field<P>(1) == finite_field<P>(3) - finite_field<P>(2));
    assert(finite_field<P>(1) == finite_field<P>(1234567890) - finite_field<P>(1234567889));

    assert(finite_field<P>(6) == finite_field<P>(3) * finite_field<P>(2));
    assert(finite_field<P>(1234567889) == finite_field<P>(1234567890) * finite_field<P>(2));

    assert(finite_field<P>(2).inverse() == finite_field<P>(617283946));

    assert(finite_field<P>(3) == finite_field<P>(6) / finite_field<P>(2));
    assert(finite_field<P>(1234567890) == finite_field<P>(1234567889) / finite_field<P>(2));

    assert(finite_field<P>(1) < finite_field<P>(2));

    assert(finite_field<P>(2) > finite_field<P>(1));

    assert(finite_field<P>(1) <= finite_field<P>(2));

    assert(finite_field<P>(2) >= finite_field<P>(1));

    assert(finite_field<P>(1) <= finite_field<P>(1));

    assert(finite_field<P>(1) >= finite_field<P>(1));

    assert(finite_field<P>(1) != finite_field<P>(2));

    assert(finite_field<P>(1) == finite_field<P>(1));

    std::cout << finite_field<P>(13) << std::endl;
    return 0;
}
