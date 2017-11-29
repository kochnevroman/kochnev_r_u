#pragma once
#ifndef RATIONAL_RATIONAL_H
#define RATIONAL_RATIONAL_H

#include <iosfwd>

class Rational
{
public:
    Rational() = default;
    explicit Rational(const int num);;
    Rational(const int num, const int denom);
    Rational(const Rational& rational) = default;

    Rational& operator=(const Rational& rational);

    bool operator==(const Rational& rational);
    bool operator!=(const Rational& rational);

    // Перегрузка основных операторов.
    Rational& operator+=(const Rational& rational);
    Rational& operator-=(const Rational& rational);
    Rational& operator*=(const Rational& rational);
    Rational& operator/=(const Rational& rational);

    // Проверка равенства числителя и знаменателя для вывода.
    bool isUnitFraction();

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

private:
    int num_  { 0 };
    int denom_{ 1 };

    static const char leftBrace{ '{' };
    static const char separator{ '/' };
    static const char rightBrace{ '}' };
};

Rational operator+(const Rational& firstRational, const Rational& secondRational);
Rational operator-(const Rational& firstRational, const Rational& secondRational);
Rational operator*(const Rational& firstRational, const Rational& secondRational);
Rational operator/(const Rational& firstRational, const Rational& secondRational);


inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rational)
{
    return rational.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Rational& rational)
{
    return rational.readFrom(istrm);
}

#endif //RATIONAL_RATIONAL_H
