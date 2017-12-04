#include "quaternion.h"
#include <iostream>
#include <cmath>

Quaternion::Quaternion(const double a, const double b, const double c, const double d)
        : a_(a)
        , b_(b)
        , c_(c)
        , d_(d)
{
}

Quaternion::Quaternion(const Quaternion& quaternion)
        : a_(quaternion.a_)
        , b_(quaternion.b_)
        , c_(quaternion.c_)
        , d_(quaternion.d_)
{
}

Quaternion& Quaternion::operator=(const Quaternion& quaternion)
{
    a_ = quaternion.a_;
    b_ = quaternion.b_;
    c_ = quaternion.d_;
    d_ = quaternion.d_;
    return *this;
}

bool Quaternion::operator==(const Quaternion& quaternion)
{
    double eps0 = 0.00001;
    return((abs(quaternion.a_ - a_) < eps0) && (abs(quaternion.b_ - b_) < eps0)
           && (abs(quaternion.c_ - c_) < eps0) && (abs(quaternion.d_ - d_) < eps0));
}

bool Quaternion::operator!=(const Quaternion& quaternion)
{
    return !operator==(quaternion);
}

Quaternion& Quaternion::operator+=(const Quaternion& quaternion)
{
    a_ += quaternion.a_;
    b_ += quaternion.b_;
    c_ += quaternion.c_;
    d_ += quaternion.d_;
    return *this;
}

Quaternion& Quaternion::operator-=(const Quaternion& quaternion)
{
    a_ -= quaternion.a_;
    b_ -= quaternion.b_;
    c_ -= quaternion.c_;
    d_ -= quaternion.d_;

    return *this;
}

Quaternion& Quaternion::operator*=(const Quaternion& quaternion)
{
    a_ = a_ * quaternion.a_ - b_ * quaternion.b_ - c_ * quaternion.c_ - d_ * quaternion.d_;
    b_ = a_ * quaternion.b_ + b_ * quaternion.a_ + c_ * quaternion.d_ - d_ * quaternion.c_;
    c_ = a_ * quaternion.c_ - b_ * quaternion.d_ + c_ * quaternion.a_ + d_ * quaternion.b_;
    d_ = a_ * quaternion.d_ + b_ * quaternion.c_ + c_ * quaternion.b_ + d_ * quaternion.a_;
    return *this;
}

Quaternion& Quaternion::operator*=(const double number)
{
    a_ += number;
    b_ += number;
    c_ += number;
    d_ += number;
    return *this;
}

Quaternion& Quaternion::operator/=(const double number)
{
    a_ /= number;
    b_ /= number;
    c_ /= number;
    d_ /= number;
    return *this;
}

Quaternion Quaternion::conjugating()
{
    return Quaternion(a_, -b_, -c_, -d_);
}

double Quaternion::module() const
{
    return sqrt( pow(a_, 2) +  pow(b_, 2) + pow (c_, 2) + pow(d_, 2) );

}

double Quaternion::determinant() const
{
    return  pow( sqrt(pow(a_, 2) +  pow(b_, 2) + pow (c_, 2) + pow(d_, 2)), 4 );
}

Quaternion operator+(const Quaternion& firstQuaternion, const Quaternion& secondQuaternion)
{
    Quaternion quaternion(firstQuaternion);
    quaternion += secondQuaternion;
    return quaternion;
}

Quaternion operator-(const Quaternion& firstQuaternion, const Quaternion& secondQuaternion)
{
    Quaternion quaternion (firstQuaternion);
    return (quaternion -= secondQuaternion);
}

Quaternion operator*(const Quaternion& firstQuaternion, const Quaternion& secondQuaternion)
{
    Quaternion quaternion_(firstQuaternion);
    return (quaternion_ *= secondQuaternion);
}

Quaternion operator*(const Quaternion& quaternion, const double number)
{
    Quaternion quaternion_(quaternion);
    return (quaternion_ *= number);
}

Quaternion operator*(const double number, const Quaternion& quaternion)
{
    Quaternion quaternion_(quaternion);
    return (quaternion_ *= number);
}

std::ostream& operator<<(std::ostream& ostrm, const Quaternion& quaternion)
{
    return quaternion.writeTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, Quaternion& quaternion)
{
    return quaternion.readFrom(istrm);
}


std::ostream& Quaternion::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << a_ << separator << space << b_ << separator << space << c_ << separator << space << d_
          << rightBrace;
    return ostrm;
}

std::istream& Quaternion::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    char separator(0);
    char space(0);
    char rightBrace(0);
    double a(0.0);
    double b(0.0);
    double c(0.0);
    double d(0.0);
    istrm >> leftBrace >> a_ >> separator >> space >> b_ >> separator >> space >> c_ >> separator >> space >> d_
          >> rightBrace;
    if (istrm.good()) {
        if ((Quaternion::leftBrace == leftBrace) && (Quaternion::separator == separator)
            && (Quaternion::rightBrace == rightBrace)) {
            a_ = a;
            b_ = b;
            c_ = c;
            d_ = d;
        } else {
            istrm.setstate(std::ios_base::failbit);
        }
    }

    return istrm;
}
