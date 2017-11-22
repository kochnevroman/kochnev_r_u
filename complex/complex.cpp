#include "complex.h"
#include <iostream>
#include <cmath>

//конструктор только для действительной части, мнимая по умолчанию 0.0
Complex::Complex(const double real) : Complex(real, 0.0) {
}

//конструктор для действительной и мнимой части
Complex::Complex(const double real, const double imaginary) {
    re = real;
    im = imaginary;
}

bool Complex::operator==(const Complex &rhs) const {
    double eps0 = 0.0000001;
    return (abs(re - rhs.re) < eps0 ) && (abs(im - rhs.im) < eps0);
}

bool Complex::operator!=(const Complex &rhs) const {
    return !operator==(rhs);
}

Complex& Complex::operator+=(const Complex& rhs) {
    re += rhs.re;
    im += rhs.im;
    return *this;
}

Complex& Complex::operator+=(const double rhs) {
    return operator+=(Complex(rhs));
}

Complex& Complex::operator-=(const Complex& rhs) {
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}

Complex& Complex::operator-=(const double rhs) {
    return operator-=(Complex(rhs));
}

//проверить
Complex& Complex::operator*=(const Complex& rhs) {
    double complex(re);

    re = rhs.re * complex - rhs.im * im;
    im = rhs.re * im + rhs.im * complex;
    //lhs.re * a.re - lhs.im * a.im, lhs.re * a.im + a.im * lhs.re

    return *this;
}

Complex& Complex::operator*=(const double rhs) {
    re *= rhs;
    im *= rhs;

    return *this;
}

//проверить
Complex& Complex::operator/=(const Complex& rhs) {
    double h(re);
    double k(im);

    re = (rhs.re*h + rhs.im*k) / (rhs.re*rhs.re + rhs.im*rhs.im);
    im = (rhs.im*h - rhs.re*k) / (rhs.re*rhs.re + rhs.im*rhs.im);

    return *this;
}

Complex& Complex::operator/=(const double rhs) {
    re /= rhs;
    im /= rhs;

    return *this;
}

//сопряженное комплексное число
Complex Complex::conjugateNumber() {
    Complex complex;
    complex.re = re;
    complex.im = -im;
    return complex;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
    Complex sum(lhs);
    sum += rhs;
    return sum;
}

Complex operator+(const double number, const Complex& rhs) {
    Complex sum(rhs);
    sum += number;
    return sum;
}

Complex operator+(const Complex& rhs, const double number) {
    Complex sum(rhs);
    sum += number;
    return sum;
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex operator-(const double number, const Complex& rhs) {
    Complex sum(rhs);
    sum -= number;
    return sum;
}

Complex operator-(const Complex& lhs, const double number) {
    Complex sum(lhs);
    sum -= number;
    return sum;
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.re * rhs.re - lhs.im * rhs.im, lhs.re * rhs.im + rhs.im * lhs.re);
}

Complex operator*(const Complex& lhs, const double rhs) {
    Complex a = Complex(rhs);
    return Complex(lhs.re * a.re - lhs.im * a.im, lhs.re * a.im + a.im * lhs.re);

    // Произведение комплексных чисел a + b·i, и a′ + b′·i равно:
    // (a + bi)·(a′+b′i) = (a·a′− b·b′) + (a·b′ + b·a′)i
}

Complex operator*(const double lhs, const Complex& rhs) {
    Complex a = Complex(lhs);
    return Complex(a.re * rhs.re - a.im * rhs.im, a.re * rhs.im + rhs.im * a.re);
}

Complex operator/(const Complex& lhs, const Complex& rhs) {

}

Complex operator/(const double lhs, const Complex& rhs) {

}

Complex operator/(const Complex& lhs, const double rhs) {

}

Complex operator^(const Complex& complex, const double exponent) {

}

Complex root (const Complex& complex, const double degreeOfRoot) {

}


std::ostream& Complex::writeTo(std::ostream& ostrm) const {
    ostrm << leftBrace << re << separator << space << im << rightBrace;
    return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm) {
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
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}
