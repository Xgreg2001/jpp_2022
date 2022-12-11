#ifndef FINITE_FIELD_H
#define FINITE_FIELD_H

#include <iostream>
#include <stdexcept>

template <long p>
class finite_field
{
private:
    unsigned long value;
    bool isPrime(long number);

public:
    finite_field(long value);
    finite_field();
    ~finite_field();
    unsigned long getValue() const;
    finite_field<p> pow(finite_field<p> exponent);
    finite_field<p> inverse();
    finite_field<p> operator+(finite_field<p> other);
    finite_field<p> operator-(finite_field<p> other);
    finite_field<p> operator*(finite_field<p> other);
    finite_field<p> operator/(finite_field<p> other);
    finite_field<p> operator+=(finite_field<p> other);
    finite_field<p> operator-=(finite_field<p> other);
    finite_field<p> operator*=(finite_field<p> other);
    finite_field<p> operator-();
    bool operator==(const finite_field<p> other) const;
    bool operator!=(finite_field<p> other);
    bool operator<(finite_field<p> other);
    bool operator>(finite_field<p> other);
    bool operator<=(finite_field<p> other);
    bool operator>=(finite_field<p> other);
};

template <long p>
bool finite_field<p>::isPrime(long number)
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

template <long p>
finite_field<p>::finite_field(long value) : value(value % p)
{
    if (!isPrime(p))
        throw std::invalid_argument("p is not prime");
}

template <long p>
finite_field<p>::finite_field() : value(0)
{
    if (!isPrime(p))
        throw std::invalid_argument("p is not prime");
}

template <long p>
finite_field<p>::~finite_field()
{
}

template <long p>
unsigned long finite_field<p>::getValue() const
{
    return value;
}

template <long p>
finite_field<p> finite_field<p>::pow(finite_field<p> exponent)
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
    return finite_field<p>(result);
}

template <long p>
finite_field<p> finite_field<p>::inverse()
{
    if (value == 0)
        throw std::invalid_argument("Cannot calculate inverse of 0");
    return pow(finite_field<p>(p - 2));
}

template <long p>
finite_field<p> finite_field<p>::operator+(finite_field<p> other)
{
    return finite_field<p>(value + other.getValue() % p);
}

template <long p>
finite_field<p> finite_field<p>::operator-(finite_field<p> other)
{
    return finite_field<p>((value - other.getValue() + p) % p);
}

template <long p>
finite_field<p> finite_field<p>::operator*(finite_field<p> other)
{
    return finite_field<p>(value * other.getValue() % p);
}

template <long p>
finite_field<p> finite_field<p>::operator/(finite_field<p> other)
{
    if (other.getValue() == 0)
        throw std::invalid_argument("Division by zero");
    return finite_field<p>(((value * other.inverse().getValue() % p) + p) % p);
}

template <long p>
finite_field<p> finite_field<p>::operator+=(finite_field<p> other)
{
    value = (value + other.getValue()) % p;
    return *this;
}

template <long p>
finite_field<p> finite_field<p>::operator-=(finite_field<p> other)
{
    value = (value - other.getValue()) % p;
    return *this;
}

template <long p>
finite_field<p> finite_field<p>::operator*=(finite_field<p> other)
{
    value = (value * other.getValue()) % p;
    return *this;
}

template <long p>
finite_field<p> finite_field<p>::operator-()
{
    return finite_field<p>(-value);
}

template <long p>
bool finite_field<p>::operator==(const finite_field<p> other) const
{
    return value == other.getValue();
}

template <long p>
bool finite_field<p>::operator!=(finite_field<p> other)
{
    return value != other.getValue();
}

template <long p>
bool finite_field<p>::operator<(finite_field<p> other)
{
    return value < other.getValue();
}

template <long p>
bool finite_field<p>::operator>(finite_field<p> other)
{
    return value > other.getValue();
}

template <long p>
bool finite_field<p>::operator<=(finite_field<p> other)
{
    return value <= other.getValue();
}

template <long p>
bool finite_field<p>::operator>=(finite_field<p> other)
{
    return value >= other.getValue();
}

template <long p>
std::ostream &operator<<(std::ostream &os, const finite_field<p> &field)
{
    os << field.getValue();
    return os;
}

#endif // FINITE_FIELD_H