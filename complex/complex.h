#pragma once
#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H

#include <iosfwd>

struct Complex {
    Complex() {}
    explicit Complex(const double real);
    Complex(const double real, const double imaginary);

    bool operator==(const Complex& rhs) const;

    bool operator!=(const Complex& rhs) const;

    Complex& operator+=(const Complex& rhs);
    Complex& operator+=(const double rhs);

    Complex& operator-=(const Complex& rhs);
    Complex& operator-=(const double rhs);

    Complex& operator*=(const Complex& rhs);
    Complex& operator*=(const double rhs);

    Complex& operator/=(const double rhs);
    Complex& operator/=(const Complex& rhs);

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

    double re{ 0.0 };
    double im{ 0.0 };

    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char space{' '};
    static const char rightBrace{ '}' };

    //сопряженное комплексное число
    Complex conjugateNumber();
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const double number, const Complex& rhs);
Complex operator+(const Complex& lhs, const double number);

Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const double number, const Complex& rhs);
Complex operator-(const Complex& lhs, const double number);

Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(const double lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const double rhs);

Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const double lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const double rhs);

//возведение в степень
Complex operator^(const Complex& complex, double exponent);
//извлечение корня
Complex root (const Complex& complex, const double degreeOfRoot);


inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
    return rhs.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Complex& rhs)
{
    return rhs.readFrom(istrm);
}

#endif //COMPLEX_COMPLEX_H
