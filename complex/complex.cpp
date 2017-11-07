#include "complex.h"

Complex::Complex(const double real) : Complex(real, 0.0) //конструктор только для действительной части, мнимая по умолчанию 0.0
{
}

Complex::Complex(const double real, const double imaginary) //конструктор для действительной и мнимой части
{
    re = real;
    im = imaginary;
}

Complex& Complex::operator+=(const Complex& rhs)
{
    re += rhs.re;
    im += rhs.im;
    return *this;
}
Complex operator+(const Complex& lhs, const Complex& rhs)
{
    Complex sum(lhs);
    sum += rhs;
    return sum;
}

Complex& Complex::operator-=(const Complex& rhs)
{
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re * rhs.re - lhs.im * rhs.im, lhs.re * rhs.im + rhs.im * lhs.re);
}

Complex operator*(const Complex& lhs, const double rhs)
{
    Complex a = Complex(rhs);

    return Complex(lhs.re * a.re - lhs.im * a.im, lhs.re * a.im + a.im * lhs.re);

    // Произведение комплексных чисел a + b·i, и a′ + b′·i равно:
    // (a + bi)·(a′+b′i) = (a·a′− b·b′) + (a·b′ + b·a′)i
}

Complex operator*(const double lhs, const Complex& rhs)
{
    Complex a = Complex(lhs);

    return Complex(a.re * rhs.re - a.im * rhs.im, a.re * rhs.im + rhs.im * a.re);
}

Complex& Complex::operator*=(const double rhs)
{
    re *= rhs;
    im *= rhs;

    return *this;
}

Complex& Complex::operator*=(const Complex& rhs)
{
    double h(re);

    re = rhs.re*h - rhs.im*im;
    im = rhs.re*im + rhs.im*h;

    return *this;
}

Complex& Complex::operator/=(const double rhs)
{
    re /= rhs;
    im /= rhs;

    return *this;
}

Complex& Complex::operator/=(const Complex& rhs)
{
    double h(re);
    double k(im);

    re = (rhs.re*h + rhs.im*k) / (rhs.re*rhs.re + rhs.im*rhs.im);
    im = (rhs.im*h - rhs.re*k) / (rhs.re*rhs.re + rhs.im*rhs.im);

    return *this;
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
    return Complex((rhs.re*lhs.re + rhs.im*lhs.im) / (lhs.re*lhs.re + lhs.im*lhs.im), (rhs.im*lhs.re - rhs.re*lhs.im) / (lhs.re*lhs.re + lhs.im*lhs.im));
}

Complex operator+(const double k, const Complex& rhs)
{
    Complex sum(rhs);
    sum += k;
    return sum;
}

