#include "vector3d_t.h"
#include <iostream>
#include <cmath>


template <typename T>
Vector3d_T::Vector3d_T(const T x, const T y, const T z) //конструктор
{
    x_ = x;
    y_ = y;
    z_ = z;
}

template <typename T>
Vector3d_T::Vector3d_T(const Vector3d_T<T>& vector3d_t) //конструктор копирования
{
    x_ = vector3d_t.x_;
    y_ = vector3d_t.y_;
    z_ = vector3d_t.z_;
}

template <typename T>
bool Vector3d_T<T>::operator==(const Vector3d_T<T>& rhs)
{
    double eps0 = 0.00001;
    return((abs(rhs.x_ - x_) < eps0) && (abs(rhs.y_ - y_) < eps0) && (abs(rhs.z_ - z_) < eps0));
}

template <typename T>
Vector3d_T<T>& Vector3d_T<T>:: operator+=(const Vector3d_T<T>& rhs) //прибавление к текущему вектору вектор
{
    x_ = rhs.x_ + x_;
    y_ = rhs.y_ + y_;
    z_ = rhs.z_ + z_;
    return *this;
}

template <typename T>
Vector3d_T<T>& Vector3d_T<T>:: operator-=(const Vector3d_T<T>& rhs) //вычитание из текущего вектора вектор
{
    x_ = x_ - rhs.x_;
    y_ = y_ - rhs.y_;
    z_ = z_ - rhs.z_;
    return *this;
}

template <typename T>
Vector3d_T<T>& Vector3d_T<T>:: operator*=(const double& rhs) //умножение вектора на число
{
    x_ = x_ * rhs;
    y_ = y_ * rhs;
    z_ = z_ * rhs;
    return *this;
}

template <typename T>
Vector3d_T<T>& Vector3d_T<T>:: operator/=(const double& rhs) //деление вектора на число
{
    x_ = x_ / rhs;
    y_ = y_ / rhs;
    z_ = z_ / rhs;
    return *this;
}

template <typename T>
Vector3d_T<T> operator+(const Vector3d_T<T>& lhs, const Vector3d_T<T>& rhs) //сложение двух векторов
{
    return Vector3d_T<T>(lhs.x_ + rhs.x_, lhs.y_ + rhs.y_, lhs.z_ + rhs.z_);
}

template <typename T>
Vector3d_T<T> operator-(const Vector3d_T<T>& lhs, const Vector3d_T<T>& rhs) //вычитание двух векторов
{
    return Vector3d_T<T>(lhs.x_ - rhs.x_, lhs.y_ - rhs.y_, lhs.z_ - rhs.z_);
}

template <typename T>
Vector3d_T<T> scalarProduct(const Vector3d_T<T>& lhs, const Vector3d_T<T>& rhs) //скалярное произведение двух векторов
{
    return Vector3d_T<T>(lhs.x_ * rhs.x_, lhs.y_ * rhs.y_, lhs.z_ * rhs.z_);
}

template <typename T>
double length (const Vector3d_T<T>& rhs) //длина вектора
{
    return sqrt(pow(rhs.x_, 2) + pow(rhs.y_, 2) + pow(rhs.z_, 2));
}


template <typename T>
std::ostream& Vector3d_T<T>::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << x_ << separator << y_ << separator << z_ << rightBrace;
    return ostrm;
}

template <typename T>
std::istream& Vector3d_T<T>::readFrom(std::istream& istrm)
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
        if ((Vector3d_T<T>::leftBrace == leftBrace) && (Vector3d_T<T>::separator == s)
            && (Vector3d_T<T>::rightBrace == rightBrace))
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
