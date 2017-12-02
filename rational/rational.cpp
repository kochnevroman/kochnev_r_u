#include "rational.h"
#include <iostream>

Rational::Rational(const int num)
        : num_(num)
{
}

Rational::Rational(const int num, const int denom)
        : num_(num)
        , denom_(denom)
{
    if (denom == 0) {
        throw std::invalid_argument("The determinator can not be zero");
    }
}

Rational& Rational::operator=(const Rational& rational)
{
    num_ = rational.num_;
    denom_ = rational.denom_;
    return *this;
}

bool Rational::operator==(const Rational& rational)
{
    return(num_ * rational.denom_ == rational.num_ * denom_);
}

bool Rational::operator!=(const Rational& rational)
{
    return !operator==(rational);
}

Rational& Rational::operator+=(const Rational& rational)
{
    num_ = num_*rational.denom_ + rational.num_*denom_;
    denom_ = denom_*rational.denom_;

    if (isUnitFraction()) {
        num_ = 1, denom_ = 1;
    }
    return *this;
}

Rational& Rational::operator-=(const Rational& rational) {
    num_ = num_*rational.denom_ - rational.num_*denom_;
    denom_ = denom_*rational.denom_;

    if (isUnitFraction()) {
        num_ = 1, denom_ = 1;
    }
    return *this;
}

Rational& Rational::operator*=(const Rational& rational) {
    num_ = rational.num_*num_;
    denom_ = rational.denom_*denom_;

    if (isUnitFraction()) {
        num_ = 1, denom_ = 1;
    }
    return *this;
}


Rational& Rational::operator/=(const Rational& rational) {
    num_ = num_*rational.denom_;
    denom_ = rational.num_*denom_;

    if (isUnitFraction()) {
        num_ = 1, denom_ = 1;
    }
    return *this;
}

bool Rational::isUnitFraction()
{
    if (num_== denom_) {
        return true;
    }
    return false;
}

Rational operator+(const Rational& firstRational, const Rational& secondRational)
{
    Rational rational(firstRational);
    rational += secondRational;
    return rational;
}

Rational operator-(const Rational& firstRational, const Rational& secondRational)
{
    Rational rational(firstRational);
    rational -= secondRational;
    return rational;
}

Rational operator*(const Rational& firstRational, const Rational& secondRational)
{
    Rational rational(firstRational);
    rational *= secondRational;
    return rational;
}

Rational operator/(const Rational& firstRational, const Rational& secondRational)
{
    Rational rational(firstRational);
    rational /= secondRational;
    return rational;
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rational)
{
    return rational.writeTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, Rational& rational)
{
    return rational.readFrom(istrm);
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
    char separator(0);
    int denom(0);
    char rightBrace(0);
    istrm >> leftBrace >> num_ >> separator >> denom_ >> rightBrace;
    if (istrm.good()) {
        if ((Rational::leftBrace == leftBrace) && (Rational::separator == separator)
            && (Rational::rightBrace == rightBrace)) {
            num_ = num;
            denom_ = denom;
        } else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}


