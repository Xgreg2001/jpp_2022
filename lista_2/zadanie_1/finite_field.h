#ifndef FINITE_FIELD_H
#define FINITE_FIELD_H

#include <iostream>

class finite_field
{
private:
    const unsigned long p = 1234567891;
    const unsigned long value;

public:
    finite_field(int value) : value(value % p){};
    finite_field(long value) : value(value % p){};
    finite_field(long long value) : value(value % p){};
    finite_field(unsigned int value) : value(value % p){};
    finite_field(unsigned long value) : value(value % p){};
    finite_field(unsigned long long value) : value(value % p){};
    ~finite_field();
    unsigned long getValue() const;
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