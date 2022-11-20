#include "finite_field.h"
#include <cassert>

int main()
{
    finite_field a = finite_field(1);
    finite_field b = finite_field(2);

    assert(a + b == finite_field(3));

    assert(finite_field(1234567891) == finite_field(0));

    assert(finite_field(3) == finite_field(1) + finite_field(2));
    assert(finite_field(3) == finite_field(1234567890) + finite_field(4));

    assert(finite_field(1) == finite_field(3) - finite_field(2));
    assert(finite_field(1) == finite_field(1234567890) - finite_field(1234567889));

    assert(finite_field(6) == finite_field(3) * finite_field(2));
    assert(finite_field(1234567889) == finite_field(1234567890) * finite_field(2));

    assert(finite_field(2).inverse() == finite_field(617283946));

    assert(finite_field(3) == finite_field(6) / finite_field(2));
    assert(finite_field(1234567890) == finite_field(1234567889) / finite_field(2));

    assert(finite_field(1) < finite_field(2));

    assert(finite_field(2) > finite_field(1));

    assert(finite_field(1) <= finite_field(2));

    assert(finite_field(2) >= finite_field(1));

    assert(finite_field(1) <= finite_field(1));

    assert(finite_field(1) >= finite_field(1));

    assert(finite_field(1) != finite_field(2));

    assert(finite_field(1) == finite_field(1));

    std::cout << finite_field(13) << std::endl;
    return 0;
}
