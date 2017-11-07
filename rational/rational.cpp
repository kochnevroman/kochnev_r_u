//
// Created by Roman Kochnev on 29.09.2017.
//

#include "rational.h"

bool Rational::operator==(const Rational& rhs)
{
    return(num_ *rhs.denom_ == rhs.num_*denom_);
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


