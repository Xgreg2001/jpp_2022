#include "finite_field.h"
#include <cassert>

int main()
{
    finite_field a = finite_field(1, 1234567891);
    finite_field b = finite_field(2, 1234567891);

    assert(a + b == finite_field(3, 1234567891));

    assert(finite_field(1234567891, 1234567891) == finite_field(0, 1234567891));

    assert(finite_field(3, 1234567891) == finite_field(1, 1234567891) + finite_field(2, 1234567891));
    assert(finite_field(3, 1234567891) == finite_field(1234567890, 1234567891) + finite_field(4, 1234567891));

    assert(finite_field(1, 1234567891) == finite_field(3, 1234567891) - finite_field(2, 1234567891));
    assert(finite_field(1, 1234567891) == finite_field(1234567890, 1234567891) - finite_field(1234567889, 1234567891));

    assert(finite_field(6, 1234567891) == finite_field(3, 1234567891) * finite_field(2, 1234567891));
    assert(finite_field(1234567889, 1234567891) == finite_field(1234567890, 1234567891) * finite_field(2, 1234567891));

    assert(finite_field(2, 1234567891).inverse() == finite_field(617283946, 1234567891));

    assert(finite_field(3, 1234567891) == finite_field(6, 1234567891) / finite_field(2, 1234567891));
    assert(finite_field(1234567890, 1234567891) == finite_field(1234567889, 1234567891) / finite_field(2, 1234567891));

    assert(finite_field(1, 1234567891) < finite_field(2, 1234567891));

    assert(finite_field(2, 1234567891) > finite_field(1, 1234567891));

    assert(finite_field(1, 1234567891) <= finite_field(2, 1234567891));

    assert(finite_field(2, 1234567891) >= finite_field(1, 1234567891));

    assert(finite_field(1, 1234567891) <= finite_field(1, 1234567891));

    assert(finite_field(1, 1234567891) >= finite_field(1, 1234567891));

    assert(finite_field(1, 1234567891) != finite_field(2, 1234567891));

    assert(finite_field(1, 1234567891) == finite_field(1, 1234567891));

    std::cout << finite_field(13, 1234567891) << std::endl;
    return 0;
}
