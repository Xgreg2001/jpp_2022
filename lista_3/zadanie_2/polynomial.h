#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <vector>
#include <iostream>
#include <cmath>

template <typename T>
class Polynomial
{
private:
    std::vector<T> coefficients;

public:
    Polynomial(std::vector<T> coefficients);
    ~Polynomial();
    std::vector<T> getCoefficients() const;
    T evaluate(T x);
    size_t degree();
    Polynomial<T> operator+(Polynomial<T> other);
    Polynomial<T> operator-(Polynomial<T> other);
    Polynomial<T> operator*(Polynomial<T> other);
    Polynomial<T> operator/(Polynomial<T> other);
    Polynomial<T> operator%(Polynomial<T> other);
    bool operator==(Polynomial<T> other);
    bool operator!=(Polynomial<T> other);
    bool operator<(Polynomial<T> other);
    bool operator>(Polynomial<T> other);
    bool operator<=(Polynomial<T> other);
    bool operator>=(Polynomial<T> other);
    friend std::ostream &operator<<(std::ostream &os, const Polynomial<T> &polynomial)
    {
        for (size_t i = 0; i < polynomial.coefficients.size(); i++)
        {
            os << polynomial.coefficients[i] << "x^" << i << " ";
        }
        return os;
    }
};

template <typename T>
Polynomial<T>::Polynomial(std::vector<T> coefficients)
{

    while (coefficients.size() > 1 && coefficients.back() == 0)
    {
        coefficients.pop_back();
    }
    this->coefficients = coefficients;
}

template <typename T>
T my_pow(T x, size_t n)
{
    T result = 1;
    for (size_t i = 0; i < n; i++)
    {
        result *= x;
    }
    return result;
}

template <typename T>
Polynomial<T>::~Polynomial()
{
}

template <typename T>
std::vector<T> Polynomial<T>::getCoefficients() const
{
    return coefficients;
}

template <typename T>
T Polynomial<T>::evaluate(T x)
{
    T result = T();
    for (size_t i = 0; i < coefficients.size(); i++)
    {
        result += coefficients[i] * my_pow(x, i);
    }
    return result;
}

template <typename T>
size_t Polynomial<T>::degree()
{
    return coefficients.size() - 1;
}

template <typename T>
Polynomial<T> Polynomial<T>::operator+(Polynomial<T> other)
{
    std::vector<T> result;
    size_t i = 0;
    while (i < coefficients.size() && i < other.coefficients.size())
    {
        result.push_back(coefficients[i] + other.coefficients[i]);
        i++;
    }
    while (i < coefficients.size())
    {
        result.push_back(coefficients[i]);
        i++;
    }
    while (i < other.coefficients.size())
    {
        result.push_back(other.coefficients[i]);
        i++;
    }
    return Polynomial<T>(result);
}

template <typename T>
Polynomial<T> Polynomial<T>::operator-(Polynomial<T> other)
{
    std::vector<T> result;
    size_t i = 0;
    while (i < coefficients.size() && i < other.coefficients.size())
    {
        result.push_back(coefficients[i] - other.coefficients[i]);
        i++;
    }
    while (i < coefficients.size())
    {
        result.push_back(coefficients[i]);
        i++;
    }
    while (i < other.coefficients.size())
    {
        result.push_back(-other.coefficients[i]);
        i++;
    }
    return Polynomial<T>(result);
}

template <typename T>
Polynomial<T> Polynomial<T>::operator*(Polynomial<T> other)
{
    std::vector<T> result(coefficients.size() + other.coefficients.size() - 1, 0);
    for (size_t i = 0; i < coefficients.size(); i++)
    {
        for (size_t j = 0; j < other.coefficients.size(); j++)
        {
            result[i + j] += coefficients[i] * other.coefficients[j];
        }
    }
    return Polynomial<T>(result);
}

template <typename T>
Polynomial<T> Polynomial<T>::operator/(Polynomial<T> other)
{
    Polynomial<T> dividend = *this;
    Polynomial<T> divisor = other;
    Polynomial<T> result = Polynomial<T>(std::vector<T>());
    while (dividend.coefficients.size() >= divisor.coefficients.size())
    {
        T coefficient = dividend.coefficients[dividend.coefficients.size() - 1] / divisor.coefficients[divisor.coefficients.size() - 1];
        size_t degree = dividend.coefficients.size() - divisor.coefficients.size();
        std::vector<T> new_coefficients(degree + 1, 0);
        new_coefficients[degree] = coefficient;
        Polynomial<T> new_polynomial(new_coefficients);
        result = result + new_polynomial;
        dividend = dividend - divisor * new_polynomial;
        while (dividend.coefficients.size() > 0 && dividend.coefficients.back() == 0)
        {
            dividend.coefficients.pop_back();
        }
    }
    return result;
}

template <typename T>
Polynomial<T> Polynomial<T>::operator%(Polynomial<T> other)
{
    Polynomial<T> dividend = *this;
    Polynomial<T> divisor = other;
    while (dividend.coefficients.size() >= divisor.coefficients.size())
    {
        T coefficient = dividend.coefficients[dividend.coefficients.size() - 1] / divisor.coefficients[divisor.coefficients.size() - 1];
        size_t degree = dividend.coefficients.size() - divisor.coefficients.size();
        std::vector<T> new_coefficients(degree + 1, 0);
        new_coefficients[degree] = coefficient;
        Polynomial<T> new_polynomial(new_coefficients);
        dividend = dividend - divisor * new_polynomial;
        while (dividend.coefficients.size() > 0 && dividend.coefficients[dividend.coefficients.size() - 1] == 0)
        {
            dividend.coefficients.pop_back();
        }
    }
    return dividend;
}

template <typename T>
bool Polynomial<T>::operator==(Polynomial<T> other)
{
    if (coefficients.size() != other.coefficients.size())
        return false;
    for (size_t i = 0; i < coefficients.size(); i++)
    {
        if (coefficients[i] != other.coefficients[i])
            return false;
    }
    return true;
}

template <typename T>
bool Polynomial<T>::operator!=(Polynomial<T> other)
{
    return !(*this == other);
}

template <typename T>
bool Polynomial<T>::operator<(Polynomial<T> other)
{
    if (coefficients.size() < other.coefficients.size())
        return true;
    if (coefficients.size() > other.coefficients.size())
        return false;
    for (size_t i = coefficients.size() - 1; i >= 0; i--)
    {
        if (coefficients[i] < other.coefficients[i])
            return true;
        if (coefficients[i] > other.coefficients[i])
            return false;
    }
    return false;
}

template <typename T>
bool Polynomial<T>::operator>(Polynomial<T> other)
{
    return other < *this;
}

template <typename T>
bool Polynomial<T>::operator<=(Polynomial<T> other)
{
    return !(*this > other);
}

template <typename T>
bool Polynomial<T>::operator>=(Polynomial<T> other)
{
    return !(*this < other);
}

#endif // POLYNOMIAL_H