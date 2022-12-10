#include "finite_field.h"
#include "polynomial.h"
#include <cassert>

int main()
{
    {
        std::vector<double> coefficients = {1, 2, 3};
        Polynomial<double> polynomial(coefficients);
        assert(polynomial.getCoefficients() == coefficients);
        assert(polynomial.evaluate(2) == 17);

        std::vector<double> coefficients2 = {2, 4};
        Polynomial<double> polynomial2(coefficients2);

        assert(polynomial + polynomial2 == Polynomial<double>({3, 6, 3}));
        assert(polynomial - polynomial2 == Polynomial<double>({-1, -2, 3}));
        assert(polynomial * polynomial2 == Polynomial<double>({2, 8, 14, 12}));

        assert(polynomial / polynomial2 == Polynomial<double>({0.125, 0.75}));
        assert(polynomial % polynomial2 == Polynomial<double>({0.75}));

        assert(polynomial == polynomial / polynomial2 * polynomial2 + polynomial % polynomial2);

        assert(polynomial == polynomial);
        assert(polynomial != polynomial2);
        assert(polynomial > polynomial2);
        assert(polynomial >= polynomial2);
        assert(polynomial2 < polynomial);
        assert(polynomial2 <= polynomial);

        std::cout << polynomial << std::endl;
        std::cout << polynomial2 << std::endl;
    }

    {
        const long P = 2;
        std::vector<finite_field<P>> coefficients = {};
        coefficients.push_back(finite_field<P>(1));
        coefficients.push_back(finite_field<P>(0));
        coefficients.push_back(finite_field<P>(1));
        coefficients.push_back(finite_field<P>(1));

        Polynomial<finite_field<P>> polynomial(coefficients);

        assert(polynomial.getCoefficients() == coefficients);

        std::vector<finite_field<P>> coefficients2 = {};
        coefficients2.push_back(finite_field<P>(1));
        coefficients2.push_back(finite_field<P>(1));

        Polynomial<finite_field<P>> polynomial2(coefficients2);

        assert(polynomial.evaluate(finite_field<P>(1)) == finite_field<P>(1));

        assert(polynomial + polynomial2 == Polynomial<finite_field<P>>({finite_field<P>(0), finite_field<P>(1), finite_field<P>(1), finite_field<P>(1)}));
        assert(polynomial - polynomial2 == Polynomial<finite_field<P>>({finite_field<P>(0), finite_field<P>(1), finite_field<P>(1), finite_field<P>(1)}));
        assert(polynomial * polynomial2 == Polynomial<finite_field<P>>({finite_field<P>(1), finite_field<P>(1), finite_field<P>(1), finite_field<P>(0), finite_field<P>(1)}));
        assert(polynomial / polynomial2 == Polynomial<finite_field<P>>({finite_field<P>(0), finite_field<P>(0), finite_field<P>(1)}));
        assert(polynomial % polynomial2 == Polynomial<finite_field<P>>({finite_field<P>(1)}));

        assert(polynomial == polynomial / polynomial2 * polynomial2 + polynomial % polynomial2);

        assert(polynomial == polynomial);
        assert(polynomial != polynomial2);
        assert(polynomial > polynomial2);
        assert(polynomial >= polynomial2);
        assert(polynomial2 < polynomial);
        assert(polynomial2 <= polynomial);

        std::cout << polynomial << std::endl;
        std::cout << polynomial2 << std::endl;
    }

    return 0;
}
