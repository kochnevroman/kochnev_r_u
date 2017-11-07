//
// Created by Roman Kochnev on 29.09.2017.
//

#ifndef RATIONAL_RATIONAL_H
#define RATIONAL_RATIONAL_H

#include <iosfwd>
#include <iostream>

class Rational
{
public:
    Rational() {}
    Rational(const int num) : num_(num) {}   //Конструктор для целого числа
    Rational(const int num, const int denom) : num_(num), denom_(denom) //Конструктор для дробного числа
    {
        if (denom == 0)
        {
            throw "Знаменатель не может равняться нулю";
        }
    }

    bool operator==(const Rational& rhs);
    bool operator!=(const Rational& rhs) { return !operator==(rhs); }

    //Перегрузка основных операторов
    Rational& operator+=(const Rational& rhs);
    Rational& operator-=(const Rational& rhs);
    Rational& operator*=(const Rational& rhs);
    Rational& operator/=(const Rational& rhs);

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

private:
int num_{ 0 };
int denom_{ 1 };

static const char leftBrace{ '{' };
static const char separator{ '/' };
static const char rightBrace{ '}' };

};

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
    return rhs.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Rational& rhs)
{
    return rhs.readFrom(istrm);
}

#endif //RATIONAL_RATIONAL_H
