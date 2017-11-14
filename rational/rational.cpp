#include "rational.h"
#include <iostream>

Rational::Rational(const int num) //Конструктор целого числа
        : num_(num)
{
}

Rational::Rational(const int num, const int denom) //Конструктор дробного числа
        : num_(num),
          denom_(denom)
{
    if (denom == 0)
    {
        throw "Знаменатель не может равняться нулю";
    }
}

bool Rational::operator==(const Rational& rhs)
{
    return(num_ *rhs.denom_ == rhs.num_*denom_);
}

bool Rational::operator!=(const Rational &rhs)
{
    return !operator==(rhs);
}

Rational& Rational::operator+=(const Rational& rhs)
{
    num_ = num_*rhs.denom_ + rhs.num_*denom_;
    denom_ = denom_*rhs.denom_;
    if (num_== denom_) { num_ = 1, denom_ = 1; }
    return *this;
}

Rational& Rational::operator-=(const Rational& rhs)
{
    num_ = num_*rhs.denom_ - rhs.num_*denom_;
    denom_ = denom_*rhs.denom_;
    if (num_== denom_) { num_ = 1, denom_ = 1; }
    return *this;
}

Rational& Rational::operator*=(const Rational& rhs)
{
    num_ = rhs.num_*num_;
    denom_ = rhs.denom_*denom_;
    if (num_== denom_) { num_ = 1, denom_ = 1; }
    return *this;
}


Rational& Rational::operator/=(const Rational& rhs)
{
    num_ = num_*rhs.denom_;
    denom_ = rhs.num_*denom_;
    if (num_== denom_) { num_ = 1, denom_ = 1; }
    return *this;
}

Rational operator+(const Rational& lhs, const Rational& rhs) //?
{
    if (lhs.num_ + rhs.num_ == lhs.denom_ + rhs.denom_) { return Rational(1.0, 1.0); }
    return Rational(lhs.num_ + rhs.num_, lhs.denom_ + rhs.denom_);
}

Rational operator-(const Rational& lhs, const Rational& rhs) //?
{
    if (lhs.num_ - rhs.num_ == lhs.denom_ - rhs.denom_) { return Rational(1.0, 1.0); }
    return Rational(lhs.num_ - rhs.num_, lhs.denom_ - rhs.denom_);
}

Rational operator*(const Rational& lhs, const Rational& rhs) //?
{
    if (lhs.num_ * rhs.num_ == lhs.denom_ * rhs.denom_) { return Rational(1.0, 1.0); }
    return Rational(lhs.num_ * rhs.num_, lhs.denom_ * rhs.denom_);
}

Rational operator/(const Rational& lhs, const Rational& rhs) //?
{
    if (lhs.num_ / rhs.num_ == lhs.denom_ / rhs.denom_) { return Rational(1.0, 1.0); }
    return Rational(lhs.num_ / rhs.num_, lhs.denom_ / rhs.denom_);
}


std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << num_ << separator << denom_ << rightBrace;
    return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    int num(0);
    char s(0);
    int denom(0);
    char rightBrace(0);
    istrm >> leftBrace >> num_ >> s >> denom_ >> rightBrace;
    if (istrm.good())
    {
        if ((Rational::leftBrace == leftBrace) && (Rational::separator == s)
            && (Rational::rightBrace == rightBrace))
        {
            num_ = num;
            denom_ = denom;
        }
        else
        {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}


