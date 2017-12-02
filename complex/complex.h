#pragma once
#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H

#include <iosfwd>

struct Complex
{
    Complex() = default;
    explicit Complex(const double real);
    Complex(const double real, const double imaginary);

    Complex& operator=(const Complex& complex);

    bool operator==(const Complex& rhs) const;
    bool operator!=(const Complex& rhs) const;

    Complex& operator+=(const Complex& rhs);
    Complex& operator+=(const double number);

    Complex& operator-=(const Complex& rhs);
    Complex& operator-=(const double number);

    Complex& operator*=(const Complex& rhs);
    Complex& operator*=(const double number);

    Complex& operator/=(const double number);
    Complex& operator/=(const Complex& rhs);

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

    double re{ 0.0 };
    double im{ 0.0 };

    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char space{' '};
    static const char rightBrace{ '}' };

    // Сопряженное комплексное число.
    Complex conjugateNumber();
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const double number, const Complex& rhs);
Complex operator+(const Complex& lhs, const double number);

Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const double number, const Complex& rhs);
Complex operator-(const Complex& lhs, const double number);

Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(const double number, const Complex& rhs);
Complex operator*(const Complex& lhs, const double number);

Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const double number, const Complex& rhs);
Complex operator/(const Complex& lhs, const double number);


std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs);
std::istream& operator>>(std::istream& istrm, Complex& rhs);

#endif //COMPLEX_COMPLEX_H
