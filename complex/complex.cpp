#include "complex.h"
#include <iostream>
#include <cmath>

Complex::Complex(const double real)
        : Complex(real, 0.0)
{
}

Complex::Complex(const double real, const double imaginary)
        : re(real)
        , im(imaginary)
{
}

Complex& operator=(const Complex& complex)
{
    re = complex.re;
    im = complex.im;
    return *this;
}

bool Complex::operator==(const Complex &rhs) const
{
    double eps0 = 0.0000001;
    return (abs(re - rhs.re) < eps0 ) && (abs(im - rhs.im) < eps0);
}

bool Complex::operator!=(const Complex &rhs) const
{
    return !operator==(rhs);
}

Complex& Complex::operator+=(const Complex& rhs)
{
    re += rhs.re;
    im += rhs.im;
    return *this;
}

Complex& Complex::operator+=(const double number)
{
    re += number;
    im += number;
    return *this;
}

Complex& Complex::operator-=(const Complex& rhs)
{
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}

Complex& Complex::operator-=(const double number)
{
    re -= number;
    im -= number;
    return *this;
}

Complex& Complex::operator*=(const Complex& rhs)
{
    re = re * rhs.re - im * rhs.im;
    im = re * rhs.im + rhs.re * im;
    return *this;
}

Complex& Complex::operator*=(const double number)
{
    re *= number;
    im *= number;
    return *this;
}

Complex& Complex::operator/=(const Complex& rhs)
{
    re = (re * rhs.re + im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
    im = (im * rhs.re - re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
    return *this;
}

Complex& Complex::operator/=(const double number)
{
    re /= number;
    im /= number;
    return *this;
}

// Cопряженное комплексное число.
Complex Complex::conjugateNumber()
{
    Complex complex;
    complex.re = re;
    complex.im = -im;
    return complex;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
    Complex sum(lhs);
    sum += rhs;
    return sum;
}

Complex operator+(const double number, const Complex& rhs)
{
    Complex sum(rhs);
    sum += number;
    return sum;
}

Complex operator+(const Complex& lhs, const double number)
{
    Complex sum(lhs);
    sum += number;
    return sum;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex operator-(const double number, const Complex& rhs)
{
    Complex sum(rhs);
    sum -= number;
    return sum;
}

Complex operator-(const Complex& lhs, const double number)
{
    Complex sum(lhs);
    sum -= number;
    return sum;
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
    Complex complex(lhs);
    complex *= rhs;
    return complex;
}

Complex operator*(const Complex& lhs, const double number)
{
    Complex complex(lhs);
    complex *= number;
    return complex;
}

Complex operator*(const double number, const Complex& rhs)
{
    Complex complex(rhs);
    complex *= number;
    return complex;
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
    Complex complex(lhs);
    complex /= rhs;
    return complex;
}

Complex operator/(const double number, const Complex& rhs)
{
    Complex complex(rhs);
    complex /= number;
    return complex;
}

Complex operator/(const Complex& lhs, const double number)
{
    Complex complex(lhs);
    complex /= number;
    return complex;
}

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
    return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs)
{
    return rhs.readFrom(istrm);
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << re << separator << space << im << rightBrace;
    return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    double real(0.0);
    char comma(0);
    double imaginary(0.0);
    char rightBrace(0);
    istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
    if (istrm.good()) {
        if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
            && (Complex::rightBrace == rightBrace)) {
            re = real;
            im = imaginary;
        } else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}
