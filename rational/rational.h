#pragma once
#ifndef RATIONAL_RATIONAL_H
#define RATIONAL_RATIONAL_H

#include <iosfwd>

class Rational
{
public:
    Rational() {}
    explicit Rational(const int num);  //Конструктор для целого числа
    Rational( int num,  int denom); //Конструктор для дробного числа

    bool operator==(const Rational& rhs);
    bool operator!=(const Rational& rhs);

    //Перегрузка основных операторов
    Rational& operator+=(const Rational& rhs);
    Rational& operator-=(const Rational& rhs);
    Rational& operator*=(const Rational& rhs);
    Rational& operator/=(const Rational& rhs);

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

    int num_{ 0 }; //числитель
    int denom_{ 1 }; //знаменатель

    static const char leftBrace{ '{' };
    static const char separator{ '/' };
    static const char rightBrace{ '}' };

    //наибольший общий делитель
    double gcd();

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
