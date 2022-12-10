#include "finite_field.h"

bool finite_field::isPrime(long number)
{
    if (number <= 1)
        return false;
    if (number <= 3)
        return true;
    if (number % 2 == 0 || number % 3 == 0)
        return false;
    for (long i = 5; i * i <= number; i = i + 6)
        if (number % i == 0 || number % (i + 2) == 0)
            return false;
    return true;
}

finite_field::finite_field(long value, long p) : p(p), value(value % p)
{
    if (!isPrime(p))
        throw std::invalid_argument("p is not prime");
}

finite_field::~finite_field()
{
}

unsigned long finite_field::getValue() const
{
    return value;
}

unsigned long finite_field::getP() const
{
    return p;
}

finite_field finite_field::pow(finite_field exponent)
{
    if (exponent.getP() != p)
    {
        throw std::invalid_argument("Exponent must be in the same field");
    }
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
    return finite_field(result, p);
}

finite_field finite_field::inverse()
{
    if (value == 0)
        throw std::invalid_argument("Cannot calculate inverse of 0");
    return pow(finite_field(p - 2, p));
}

finite_field finite_field::operator+(finite_field other)
{
    if (other.getP() != p)
    {
        throw std::invalid_argument("Cannot add elements from different fields");
    }
    return finite_field(value + other.getValue() % p, p);
}

finite_field finite_field::operator-(finite_field other)
{
    if (other.getP() != p)
    {
        throw std::invalid_argument("Cannot subtract elements from different fields");
    }
    return finite_field(value - other.getValue() % p, p);
}

finite_field finite_field::operator*(finite_field other)
{
    if (other.getP() != p)
    {
        throw std::invalid_argument("Cannot multiply elements from different fields");
    }
    return finite_field(value * other.getValue() % p, p);
}

finite_field finite_field::operator/(finite_field other)
{
    if (other.getP() != p)
    {
        throw std::invalid_argument("Cannot divide elements from different fields");
    }
    if (other.getValue() == 0)
        throw std::invalid_argument("Division by zero");
    return finite_field(value * other.inverse().getValue() % p, p);
}

bool finite_field::operator==(finite_field other)
{
    if (other.getP() != p)
    {
        throw std::invalid_argument("Cannot compare elements from different fields");
    }
    return value == other.getValue();
}

bool finite_field::operator!=(finite_field other)
{
    if (other.getP() != p)
    {
        throw std::invalid_argument("Cannot compare elements from different fields");
    }
    return value != other.getValue();
}

bool finite_field::operator<(finite_field other)
{
    if (other.getP() != p)
    {
        throw std::invalid_argument("Cannot compare elements from different fields");
    }
    return value < other.getValue();
}

bool finite_field::operator>(finite_field other)
{
    if (other.getP() != p)
    {
        throw std::invalid_argument("Cannot compare elements from different fields");
    }
    return value > other.getValue();
}

bool finite_field::operator<=(finite_field other)
{
    if (other.getP() != p)
    {
        throw std::invalid_argument("Cannot compare elements from different fields");
    }
    return value <= other.getValue();
}

bool finite_field::operator>=(finite_field other)
{
    if (other.getP() != p)
    {
        throw std::invalid_argument("Cannot compare elements from different fields");
    }
    return value >= other.getValue();
}

std::ostream &operator<<(std::ostream &os, const finite_field &field)
{
    os << field.getValue();
    return os;
}
