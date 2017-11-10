#include "vector3d.h"
#include <cmath>
#include <iostream>

Vector3d::Vector3d(const double x, const double y, const double z) //конструктор
{
    x_ = x;
    y_ = y;
    z_ = z;
}

Vector3d::Vector3d(const Vector3d& vector3d) //конструктор копирования
{
    x_ = vector3d.x_;
    y_ = vector3d.y_;
    z_ = vector3d.z_;
}

bool Vector3d::operator==(const Vector3d& rhs)
{
    double eps0 = 0.00001;
    return((abs(rhs.x_ - x_) < eps0) && (abs(rhs.y_ - y_) < eps0) && (abs(rhs.z_ - z_) < eps0));
}

Vector3d& Vector3d:: operator+=(const Vector3d& rhs) //прибавление к текущему вектору вектор
{
    x_ = rhs.x_ + x_;
    y_ = rhs.y_ + y_;
    z_ = rhs.z_ + z_;
    return *this;
}
Vector3d& Vector3d:: operator-=(const Vector3d& rhs) //вычитание из текущего вектора вектор
{
    x_ = x_ - rhs.x_;
    y_ = y_ - rhs.y_;
    z_ = z_ - rhs.z_;
    return *this;
}

Vector3d& Vector3d:: operator*=(const double& rhs) //умножение вектора на число
{
    x_ = x_ * rhs;
    y_ = y_ * rhs;
    z_ = z_ * rhs;
    return *this;
}

Vector3d& Vector3d:: operator/=(const double& rhs) //деление вектора на число
{
    x_ = x_ / rhs;
    y_ = y_ / rhs;
    z_ = z_ / rhs;
    return *this;
}

Vector3d operator+(const Vector3d& lhs, const Vector3d& rhs) //сложение двух векторов
{
    return Vector3d(lhs.x_ + rhs.x_, lhs.y_ + rhs.y_, lhs.z_ + rhs.z_);
}

Vector3d operator-(const Vector3d& lhs, const Vector3d& rhs) //вычитание двух векторов
{
    return Vector3d(lhs.x_ - rhs.x_, lhs.y_ - rhs.y_, lhs.z_ - rhs.z_);
}

Vector3d scalarProduct(const Vector3d& lhs, const Vector3d& rhs) //скалярное произведение двух векторов
{
    return Vector3d(lhs.x_ * rhs.x_, lhs.y_ * rhs.y_, lhs.z_ * rhs.z_);
}

double length (const Vector3d& rhs) //длина вектора
{
    return sqrt(pow(rhs.x_, 2) + pow(rhs.y_, 2) + pow(rhs.z_, 2));
}


std::ostream& Vector3d::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << x_ << separator << y_ << separator << z_ << rightBrace;
    return ostrm;
}

std::istream& Vector3d::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    int x(0);
    char s(0);
    int y(0);
    int z(0);
    char rightBrace(0);
    istrm >> leftBrace >> x_ >> s >> y_ >> s >> z_ >> rightBrace;
    if (istrm.good())
    {
        if ((Vector3d::leftBrace == leftBrace) && (Vector3d::separator == s)
            && (Vector3d::rightBrace == rightBrace))
        {
            x_ = x;
            y_ = y;
            z_ = z;
        }
        else
        {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}
