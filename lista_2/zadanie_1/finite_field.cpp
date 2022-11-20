#include "finite_field.h"

finite_field::~finite_field()
{
}

unsigned long finite_field::getValue() const
{
    return value;
}

finite_field finite_field::pow(finite_field exponent)
{
    unsigned long result = 1;
    unsigned long base = value;
    unsigned long exp = exponent.getValue();
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % p;
        exp = exp >> 1;
        base = (base * base) % p;
    }
    return finite_field(result);
}

finite_field finite_field::inverse()
{
    return pow(finite_field(p - 2));
}

finite_field finite_field::operator+(finite_field other)
{
    return finite_field(value + other.getValue() % p);
}

finite_field finite_field::operator-(finite_field other)
{
    return finite_field(value - other.getValue() % p);
}

finite_field finite_field::operator*(finite_field other)
{
    return finite_field(value * other.getValue() % p);
}

finite_field finite_field::operator/(finite_field other)
{
    return finite_field(value * other.inverse().getValue() % p);
}

bool finite_field::operator==(finite_field other)
{
    return value == other.getValue();
}

bool finite_field::operator!=(finite_field other)
{
    return value != other.getValue();
}

bool finite_field::operator<(finite_field other)
{
    return value < other.getValue();
}

bool finite_field::operator>(finite_field other)
{
    return value > other.getValue();
}

bool finite_field::operator<=(finite_field other)
{
    return value <= other.getValue();
}

bool finite_field::operator>=(finite_field other)
{
    return value >= other.getValue();
}

std::ostream &operator<<(std::ostream &os, const finite_field &field)
{
    os << field.getValue();
    return os;
}
