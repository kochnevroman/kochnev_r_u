//
// Created by Roman Kochnev on 25.10.2017.
//

#include "vector3d_t.h"
#include <cmath>

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

//
