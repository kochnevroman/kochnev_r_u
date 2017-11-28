#pragma once
#ifndef RATIONAL_RATIONAL_H
#define RATIONAL_RATIONAL_H

#include <iosfwd>

class Rational
{
public:
    Rational() = default;
    explicit Rational(const int num);;
    Rational( int num,  int denom);

    bool operator==(const Rational& rhs);
    bool operator!=(const Rational& rhs);

    // Перегрузка основных операторов.
    Rational& operator+=(const Rational& rhs);
    Rational& operator-=(const Rational& rhs);
    Rational& operator*=(const Rational& rhs);
    Rational& operator/=(const Rational& rhs);

    // Проверка равенства числителя и знаменателя для вывода.
    bool isUnitFraction();

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

private:
    int num_  { 0 }; // Числитель.
    int denom_{ 1 }; // Знаменатель.

    static const char leftBrace{ '{' };
    static const char separator{ '/' };
    static const char rightBrace{ '}' };
};

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);


inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
    return rhs.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Rational& rhs)
{
    return rhs.readFrom(istrm);
}

#endif //RATIONAL_RATIONAL_H
