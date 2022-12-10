#ifndef FINITE_FIELD_H
#define FINITE_FIELD_H

#include <iostream>
#include <stdexcept>

class finite_field
{
private:
    const unsigned long p;
    const unsigned long value;
    bool isPrime(long number);

public:
    finite_field(long value, long p);
    ~finite_field();
    unsigned long getValue() const;
    unsigned long getP() const;
    finite_field pow(finite_field exponent);
    finite_field inverse();
    finite_field operator+(finite_field other);
    finite_field operator-(finite_field other);
    finite_field operator*(finite_field other);
    finite_field operator/(finite_field other);
    bool operator==(finite_field other);
    bool operator!=(finite_field other);
    bool operator<(finite_field other);
    bool operator>(finite_field other);
    bool operator<=(finite_field other);
    bool operator>=(finite_field other);
    friend std::ostream &operator<<(std::ostream &os, const finite_field &field);
};

#endif // FINITE_FIELD_H