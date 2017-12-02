#include "vector3d.h"
#include <cmath>
#include <iostream>

Vector3d::Vector3d(const double x, const double y, const double z)
        : x_(x)
        , y_(y)
        , z_(z)
{
}

Vector3d::Vector3d(const Vector3d& vector3d)
        : x_(vector3d.x_)
        , y_(vector3d.y_)
        , z_(vector3d.z_)
{
}

Vector3d& Vector3d::operator=(const Vector3d& vector3d)
{
    x_ = vector3d.x_;
    y_ = vector3d.y_;
    z_ = vector3d.z_;
    return *this;
}

bool Vector3d::operator==(const Vector3d& vector3d)
{
    double eps0 = 0.000001;
    return((abs(vector3d.x_ - x_) < eps0) && (abs(vector3d.y_ - y_) < eps0) && (abs(vector3d.z_ - z_) < eps0));
}

bool Vector3d::operator!=(const Vector3d& vector3d)
{
    return !operator==(vector3d);
}

Vector3d& Vector3d::operator+=(const Vector3d& vector3d)
{
    x_ = vector3d.x_ + x_;
    y_ = vector3d.y_ + y_;
    z_ = vector3d.z_ + z_;
    return *this;
}

Vector3d& Vector3d::operator-=(const Vector3d& vector3d)
{
    x_ = x_ - vector3d.x_;
    y_ = y_ - vector3d.y_;
    z_ = z_ - vector3d.z_;
    return *this;
}

Vector3d& Vector3d::operator*=(const double number)
{
    x_ = x_ * number;
    y_ = y_ * number;
    z_ = z_ * number;
    return *this;
}

Vector3d& Vector3d::operator/=(const double number)
{
    x_ = x_ / number;
    y_ = y_ / number;
    z_ = z_ / number;
    return *this;
}

double Vector3d::scalarProduct(const Vector3d& vector3d)
{
    return (x_ * vector3d.x_, y_ * vector3d.y_, z_ * vector3d.z_);
}

double Vector3d::length()
{
    return sqrt(pow(x_, 2) + pow(y_, 2) + pow(z_, 2));
}

double Vector3d::cosineOfAngle(const Vector3d& vector3d)
{
    double firstLength = length();
    double secondLength = sqrt(pow(vector3d.x_, 2) + pow(vector3d.y_, 2) + pow(vector3d.z_, 2));

    if (firstLength != 0 && secondLength != 0) {
        return scalarProduct(vector3d) / (firstLength * secondLength);
    }
    return 1;
}

Vector3d operator+(const Vector3d& firstVector3d, const Vector3d& secondVector3d)
{
    Vector3d vector3d(firstVector3d);
    vector3d += secondVector3d;
    return vector3d;
}

Vector3d operator-(const Vector3d& firstVector3d, const Vector3d& secondVector3d)
{
    Vector3d vector3d(firstVector3d);
    vector3d -= secondVector3d;
    return vector3d;
}

Vector3d operator*(const Vector3d& vector3d, const double number)
{
    Vector3d vector3d_(vector3d);
    vector3d_ *= number;
    return vector3d_;
}

Vector3d operator*(const double number, const Vector3d& vector3d)
{
    Vector3d vector3d_(vector3d);
    vector3d_ *= number;
    return vector3d_;
}

Vector3d operator/(const Vector3d& vector3d, const double number)
{
    Vector3d vector3d_(vector3d);
    vector3d_ /= number;
    return vector3d_;
}

std::ostream& operator<<(std::ostream& ostrm, const Vector3d& vector3d)
{
    return vector3d.writeTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, Vector3d& vector3d)
{
    return vector3d.readFrom(istrm);
}

std::ostream& Vector3d::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << x_ << separator << space << y_ << separator << space << z_ << rightBrace;
    return ostrm;
}

std::istream& Vector3d::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    int x(0);
    char separator(0);
    char space(0);
    int y(0);
    int z(0);
    char rightBrace(0);
    istrm >> leftBrace >> x_ >> separator >> space >> y_ >> separator >> space >> z_ >> rightBrace;
    if (istrm.good()) {
        if ((Vector3d::leftBrace == leftBrace) && (Vector3d::separator == separator)
            && (Vector3d::rightBrace == rightBrace)) {
            x_ = x;
            y_ = y;
            z_ = z;
        } else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}
