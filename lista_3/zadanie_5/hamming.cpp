#include "finite_field.h"
#include "polynomial.h"

#include <iostream>
#include <vector>
#include <bitset>

const Polynomial<finite_field<2>> g = Polynomial<finite_field<2>>({1, 1, 0, 1});

Polynomial<finite_field<2>> hamming_encode(Polynomial<finite_field<2>> p);
Polynomial<finite_field<2>> hamming_decode(Polynomial<finite_field<2>> p);
Polynomial<finite_field<2>> uint8_to_polynomial(u_int8_t data);
u_int8_t polynomial_to_uint8(Polynomial<finite_field<2>> p);
u_int8_t hamming_encode(u_int8_t data);
u_int8_t hamming_decode(u_int8_t data);

Polynomial<finite_field<2>> hamming_encode(Polynomial<finite_field<2>> p)
{
    if (p.getCoefficients().size() > 4)
        throw std::invalid_argument("Polynomial degree must be less than 4");
    Polynomial<finite_field<2>> result = p * g;
    return result;
}

Polynomial<finite_field<2>> hamming_decode(Polynomial<finite_field<2>> p)
{
    if (p.getCoefficients().size() > 7)
        throw std::invalid_argument("Polynomial degree must be less than 7");
    if (p % g != Polynomial<finite_field<2>>({}))
    {
        std::cout << "Error detected for: " << std::bitset<8>(polynomial_to_uint8(p)) << std::endl;
    }
    Polynomial<finite_field<2>> result = p / g;
    return result;
}

Polynomial<finite_field<2>> uint8_to_polynomial(u_int8_t data)
{
    std::vector<finite_field<2>> coefficients;
    for (int i = 0; i < 8; i++)
    {
        coefficients.push_back(finite_field<2>(data & 1));
        data >>= 1;
    }
    return Polynomial<finite_field<2>>(coefficients);
}

u_int8_t polynomial_to_uint8(Polynomial<finite_field<2>> p)
{
    u_int8_t result = 0;

    for (size_t i = 0; i < p.getCoefficients().size(); i++)
    {
        result |= p.getCoefficients()[i].getValue() << i;
    }
    return result;
}

u_int8_t hamming_encode(u_int8_t data)
{
    return polynomial_to_uint8(hamming_encode(uint8_to_polynomial(data)));
}

u_int8_t hamming_decode(u_int8_t data)
{
    return polynomial_to_uint8(hamming_decode(uint8_to_polynomial(data)));
}

int main()
{
    u_int8_t data = 0b0000101;
    u_int8_t encoded_data = hamming_encode(data);
    u_int8_t corrupted_data = encoded_data ^ 0b0000010;
    u_int8_t badly_corrupted_data = encoded_data ^ 0b0001100;
    u_int8_t decoded_data = hamming_decode(encoded_data);
    u_int8_t decoded_corrupted_data = hamming_decode(corrupted_data);
    u_int8_t decoded_badly_corrupted_data = hamming_decode(badly_corrupted_data);

    std::cout << "Data: " << std::bitset<8>(data) << std::endl;
    std::cout << "Encoded data: " << std::bitset<8>(encoded_data) << std::endl;
    std::cout << "Corrupted data: " << std::bitset<8>(corrupted_data) << std::endl;
    std::cout << "Badly corrupted data: " << std::bitset<8>(badly_corrupted_data) << std::endl;
    std::cout << "Decoded data: " << std::bitset<8>(decoded_data) << std::endl;
    std::cout << "Decoded corrupted data: " << std::bitset<8>(decoded_corrupted_data) << std::endl;
    std::cout << "Decoded badly corrupted data: " << std::bitset<8>(decoded_badly_corrupted_data) << std::endl;
    return 0;
}
