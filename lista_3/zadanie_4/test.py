from finite_field import finite_field
from polynomial import polynomial


def main():
    coeficients = [1.0, 2.0, 3.0]
    p = polynomial(coeficients)

    assert (p.coefficients == coeficients)
    assert (p.evaluate(2) == 17)

    coeficients2 = [2.0, 4.0]
    p2 = polynomial(coeficients2)

    assert (p + p2 == polynomial([3.0, 6.0, 3.0]))
    assert (p - p2 == polynomial([-1.0, -2.0, 3.0]))
    assert (p * p2 == polynomial([2.0, 8.0, 14.0, 12.0]))
    assert (p / p2 == polynomial([0.125, 0.75]))
    assert (p % p2 == polynomial([0.75]))

    assert (p == p2 * (p / p2) + (p % p2))

    assert (str(p) == "3.0x^2 + 2.0x + 1.0")

    assert (p != p2)
    assert (p > p2)
    assert (p >= p2)
    assert (p2 < p)
    assert (p2 <= p)


if __name__ == '__main__':
    main()
